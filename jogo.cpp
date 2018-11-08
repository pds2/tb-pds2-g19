#include <iostream>
#include "jogo.h"
#include "carta.h"
#include "baralho.h"
#include "jogador.h"

#define MAO_INICIAL 7

	Jogo::Jogo(){
		this->_baralho = new Baralho;
		this->_sentido = 1;
		this->_jogador_atual = 0;
		

		std::string nome_jogador; 
		std::cout<<std::endl;
		std::cout << "digite o numero de jogadores : \n" << std::endl;
		std::cin >> this->_n_jogadores;
		//TRATAR EXCECOES DE ERRO DE USUARIO 

		for (unsigned int i = 0;i < _n_jogadores;i++){
			std::cout << " digite o nome do jogador  sem espaço " << i + 1 << " : " << std::endl;
			std::cin >> nome_jogador;
			//TRATAR EXCECOES DE ERRO DE USUARIO 
			Jogador *novo = new Jogador(nome_jogador);
			for (int j = 0;j < MAO_INICIAL;j++){
				novo->compra_carta(*_baralho);
			}
			novo->print_mao();
			this->_jogadores.push_back(novo);
		}
		_baralho->retira_especial_do_topo();
		_pilha_de_cartas.push_back(_baralho->get_ultima_carta());
		_baralho->remove_fim();
	}
	
	Jogo::~Jogo(){
		 while (!_pilha_de_cartas.empty()){
		 	  delete _pilha_de_cartas.front();
		 	  _pilha_de_cartas.pop_front();
		 }
		 while(!_jogadores.empty()){
		 	delete _jogadores[_jogadores.size() -1];
		 	_jogadores.pop_back();
		 }
		delete _baralho;
	}
	//METODOS
	int Jogo::get_tamanho() const{
		return _pilha_de_cartas.size();
	}



	void Jogo::print_Jogo(){
		//std::list<Carta*>::iterator it  = _pilha_de_cartas.end();
		for (std::list<Carta*>::reverse_iterator rit = _pilha_de_cartas.rbegin(); rit!=_pilha_de_cartas.rend(); ++rit)
			(*rit)->print_carta();	
	}

	int Jogo::f_rodada(){
		//this->print_Jogo();
		Carta *escolhida;
		Carta *carta_atual =  _pilha_de_cartas.back();
		std::cout << "Carta atual :  " ;
		carta_atual->print_carta();


		if (_jogadores[ _jogador_atual ] ->cartas_jogaveis(carta_atual) == 0 ){
			std::cout << _jogadores[ _jogador_atual ]->get_nome() <<" NAO POSSUI CARTAS PARA JOGAR E TEVE COMPRAR UMA " << std::endl;
			_jogadores[ _jogador_atual ]->compra_carta(*_baralho);
			//caso tenha comprado uma carta jogavel(valida)
			if (_jogadores[ _jogador_atual ] ->cartas_jogaveis(carta_atual) != 0 ){
				return f_rodada();
			}
			this->passa_rodada();
			return 1;
		}
		else if (carta_atual->get_valor() == COMPRA_2 &&_jogadores[this->_jogador_atual]->qtd_compra_2() > 0 && carta_atual->get_jogador_alvo() == _jogador_atual){
			escolhida =_jogadores[_jogador_atual]->rebate_compra_2();
		}
		else if (carta_atual->get_valor() == COMPRA_4   &&_jogadores[this->_jogador_atual]->qtd_compra_4() > 0 && carta_atual->get_jogador_alvo() == _jogador_atual){
			escolhida =_jogadores[_jogador_atual]->rebate_compra_4();
		} 
		else{
			escolhida =_jogadores[ _jogador_atual ]->jogada( carta_atual );
			
		}
		
		if(_jogadores[_jogador_atual]->num_cartas() == 0){
			std::cout << "Acabou "<<_jogadores[_jogador_atual]->get_nome() << " é o campeao" << std::endl;
			return 0;
		}
		_pilha_de_cartas.push_back(escolhida);
		this->efeitos_de_carta(escolhida);
		this->passa_rodada();
		return 1;                                                                                         
	}
	void Jogo::efeitos_de_carta(Carta *escolhida){
		
		int proximo_jogador = (this->_jogador_atual + this->_sentido) % this->_n_jogadores;
		if (proximo_jogador < 0)
			proximo_jogador += this->_n_jogadores;
		
		switch (escolhida->get_valor()){		
				case PULAR :	
						this->_jogador_atual = proximo_jogador;
	 				break;

	 			case REVERTER:
		 				if (_n_jogadores == 2)
		 					this->_jogador_atual = proximo_jogador;	
		 				else
		 					this->_sentido = -_sentido;
	 				break;

	 			case COMPRA_2:
						escolhida->set_jogador_alvo(proximo_jogador);
						if (_jogadores[proximo_jogador]->qtd_compra_2() == 0 ){

							int n_compra_2 = this->cnt_compra_2();

							for(int i = 0;i <2*n_compra_2 ;i++)
				 				this->_jogadores[proximo_jogador]->compra_carta(*_baralho);
				 			this->_jogador_atual = proximo_jogador;

						}
						else{}
	 				 break;

	 			case COMPRA_4:
	 					escolhida->set_jogador_alvo(proximo_jogador);
						if (_jogadores[proximo_jogador]->qtd_compra_4() == 0 ){
							int n_compra_4 = this->cnt_compra_4();
							for(int i = 0;i < 4*n_compra_4;i++)
				 				this->_jogadores[proximo_jogador]->compra_carta(*_baralho);
				 			this->_jogador_atual = proximo_jogador;
						}			 		
				 		escolhida->set_cor_coringa();
	 				break;

	 			case CORINGA:
	 					escolhida->set_cor_coringa();
	 				break;			 
		}
	}
	int Jogo::cnt_compra_2(){
		std::list<Carta*>::reverse_iterator rit = _pilha_de_cartas.rbegin();
		int contador = 0;
		while ( (*rit)->get_valor()  == COMPRA_2 && rit!=_pilha_de_cartas.rend() && (*rit)->get_jogador_alvo() != -1 ){
			contador = contador  + 1;
			(*rit)->set_jogador_alvo(-1);
			++rit;
		}
		//std::cout<< "QUANTIDADE DE CARTA +2 == " << contador <<std::endl;
		return contador;
	}
	int Jogo::cnt_compra_4(){
		std::list<Carta*>::reverse_iterator rit = _pilha_de_cartas.rbegin();
		int contador = 0;
		while ( (*rit)->get_valor()  == COMPRA_4   && rit !=_pilha_de_cartas.rend() && (*rit)->get_jogador_alvo() != -1){
			contador = contador  + 1;
			(*rit)->set_jogador_alvo(-1);
			++rit;
		}
		//std::cout<< "QUANTIDADE DE CARTA +4 == " << contador <<std::endl;
		return contador;
	}
	void Jogo::passa_rodada(){
		this->_jogador_atual = (this->_jogador_atual + this->_sentido) % this->_n_jogadores;			
		if (this->_jogador_atual < 0)
			this->_jogador_atual += this->_n_jogadores;
	}








