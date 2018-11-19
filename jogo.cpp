#include <iostream>
#include "jogo.h"
#include "carta.h"
#include "baralho.h"
#include "jogador.h"

#define MAO_INICIAL 7
#define MAX_NAME 80
#define MAX_PLAYERS 10

	Jogo::Jogo(){
		this->_baralho = new Baralho;
		this->_sentido = 1;
		this->_jogador_atual = 0;
		

		std::string nome_jogador; 
		std::cout<<std::endl;
		std::cout << "Digite o numero de jogadores e de bots separados por espaco :" << std::endl;

		std::cin >> this->_n_jogadores;
		std::cin >> this->_n_bots;

		//EXECAO DE ENTRADA INVALIDA TRATADA
		while((_n_jogadores + _n_bots) < 2 || (_n_jogadores + _n_bots) > 10){
			std::cout << "O jogo deve ter de 2 a 10 jogadores, escolha novos valores" << std::endl;
			std::cin >> this->_n_jogadores;
			std::cin >> this->_n_bots;
		}
		std::cin.ignore();
		for (unsigned int i = 0;i < _n_jogadores;i++){
			std::cout << "Digite o nome do jogador " << i + 1 << std::endl;

			std::getline(std::cin,nome_jogador);
			//TRATAR EXCECOES DE ERRO DE USUARIO 
			Jogador *novo = new Jogador(nome_jogador);
			for (int j = 0;j < MAO_INICIAL;j++){
				novo->compra_carta(*_baralho);
			}
			novo->print_mao();
			this->_jogadores.push_back(novo);
			std::cin.clear();
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

	int Jogo::rodada(){
		Carta *escolhida;
		Carta *carta_atual =  _pilha_de_cartas.back();
		std::cout << "Carta atual : " ;
		carta_atual->print_carta();
		
		std::cout << "Numero de cartas na pilha ==  " <<_pilha_de_cartas.size();
		std::cout << "  Numero de cartas no baralho  ==  " << _baralho->get_tamanho() << std::endl;
	
		//////////
		if(_baralho->get_tamanho() == 0){
			this->repoe_baralho();
		}
		//////////

		if (_jogadores[ _jogador_atual ] ->cartas_jogaveis(carta_atual) == 0 ){
			std::cout << _jogadores[ _jogador_atual ]->get_nome() <<" NAO POSSUI CARTAS PARA JOGAR E TEVE COMPRAR UMA " << std::endl;
			_jogadores[ _jogador_atual ]->compra_carta(*_baralho);
			//caso tenha comprado uma carta jogavel(valida)
			if (_jogadores[ _jogador_atual ] ->cartas_jogaveis(carta_atual) != 0 ){
				return rodada();
			}
			this->passa_rodada();
			return 1;
		}
		else if (carta_atual->get_valor() == COMPRA_2 &&_jogadores[this->_jogador_atual]->qtd_de_carta(COMPRA_2) > 0 && carta_atual->get_jogador_alvo() == _jogador_atual){
			escolhida =_jogadores[_jogador_atual]->rebate(COMPRA_2);
		}
		else if (carta_atual->get_valor() == COMPRA_4   &&_jogadores[this->_jogador_atual]->qtd_de_carta(COMPRA_4) > 0 && carta_atual->get_jogador_alvo() == _jogador_atual){
			escolhida =_jogadores[_jogador_atual]->rebate(COMPRA_4);
		} 
		else{
			escolhida =_jogadores[ _jogador_atual ]->jogada( carta_atual );
			
		}
		
		if(_jogadores[_jogador_atual]->num_cartas() == 0){
			std::cout << "Acabou "<<_jogadores[_jogador_atual]->get_nome() << " e o campeao" << std::endl;
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
						if (_jogadores[proximo_jogador]->qtd_de_carta(COMPRA_2) == 0 ){   //qtd_compra_2()
							int n_compra_2 = this->cnt_de_carta(COMPRA_2);//                 cnt_compra_2();
							if(n_compra_2*2 > _baralho->get_tamanho())
								this->repoe_baralho();
							for(int i = 0;i <2*n_compra_2 ;i++)
				 				this->_jogadores[proximo_jogador]->compra_carta(*_baralho);
				 			this->_jogador_atual = proximo_jogador;
						}
						else{}
	 				 break;

	 			case COMPRA_4:
	 					escolhida->set_jogador_alvo(proximo_jogador);
						_jogadores[_jogador_atual]->escolhe_cor(escolhida);
						if (_jogadores[proximo_jogador]->qtd_de_carta(COMPRA_4) == 0 ){ //qtd_compra_4()
							int n_compra_4 = this->cnt_de_carta(COMPRA_4);//          cnt_compra_4();
							if(n_compra_4*4 > _baralho->get_tamanho())
								this->repoe_baralho();
							for(int i = 0;i < 4*n_compra_4;i++)
				 				this->_jogadores[proximo_jogador]->compra_carta(*_baralho);
				 			this->_jogador_atual = proximo_jogador;
						}		 		
				 		//escolhida->set_cor_coringa();
	 				break;

	 			case CORINGA:
	 					_jogadores[_jogador_atual]->escolhe_cor(escolhida);
	 					//como era antes : escolhida->set_cor_coringa();
	 				break;			 
		}
	}
	int Jogo::cnt_de_carta(char valor){
		std::list<Carta*>::reverse_iterator rit = _pilha_de_cartas.rbegin();
		int contador = 0;
		while ( (*rit)->get_valor()  == valor && rit!=_pilha_de_cartas.rend() && (*rit)->get_jogador_alvo() != -1 ){
			contador = contador  + 1;
			(*rit)->set_jogador_alvo(-1);
			++rit;
		}
		return contador;
	}
	void Jogo::passa_rodada(){
		this->_jogador_atual = (this->_jogador_atual + this->_sentido) % this->_n_jogadores;
		if (this->_jogador_atual < 0){
			this->_jogador_atual += this->_n_jogadores;			
		}
	}
	//////////
	void Jogo::repoe_baralho(){
		std::cout<<"Acabou as carta e a pilha foi reembaralhada" <<std::endl;
		Carta *carta_atual =  _pilha_de_cartas.back();
		_pilha_de_cartas.pop_back();
		
		while(_pilha_de_cartas.size() > 0){		
			_pilha_de_cartas.back()->tira_cor_especial();//tira as cores das cartas COMPRA_4 e CORINGA voltando a ter a cor ESPECIAL		 	
			_baralho->adiciona_carta(_pilha_de_cartas.back());
			_pilha_de_cartas.pop_back();
		}
		_baralho->embaralhar();
		_pilha_de_cartas.push_back(carta_atual);		
	}
	//////////
	void Jogo::inicia_jogo(){
		while (this->rodada()){}
	}






