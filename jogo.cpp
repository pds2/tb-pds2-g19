#include <iostream>
#include "jogo.h"
#include "carta.h"
#include "baralho.h"
#include "jogador.h"

#define MAO_INICIAL 7

	Jogo::Jogo(){
		this->baralho = new Baralho;
		this->sentido = 1;
		this->jogador_atual = 0;
		this->rodada = 0;

		std::string nome_jogador; 
		std::cout<<std::endl;
		std::cout << "digite o numero de jogadores : \n" << std::endl;
		std::cin >> this->n_jogadores;

		for (unsigned int i = 0;i < n_jogadores;i++){
			std::cout << " digite o nome do jogador " << i + 1 << " : " << std::endl;
			std::cin >> nome_jogador;
			Jogador *novo = new Jogador(nome_jogador);
			for (int j = 0;j < MAO_INICIAL;j++){
				novo->compra_carta(*baralho);
			}
			novo->print_mao();
			this->jogadores.push_back(novo);
		}
		baralho->retira_especial_do_topo();
		pilha_de_cartas.push_back(baralho->get_ultima_carta());
		baralho->remove_fim();
	}
	
	Jogo::~Jogo(){
		 while (!pilha_de_cartas.empty()){
		 	  delete pilha_de_cartas.front();
		 	  pilha_de_cartas.pop_front();
		 }
		 while(!jogadores.empty()){
		 	delete jogadores[jogadores.size() -1];
		 	jogadores.pop_back();
		 }
		// delete baralho;
	}
	//METODOS
	int Jogo::get_tamanho() const{
		return pilha_de_cartas.size();
	}



	void Jogo::print_Jogo(){
		//std::list<Carta*>::iterator it  = pilha_de_cartas.end();
		for (std::list<Carta*>::reverse_iterator rit = pilha_de_cartas.rbegin(); rit!=pilha_de_cartas.rend(); ++rit)
			(*rit)->print_carta();	
	}

	int Jogo::f_rodada(){
		//this->print_Jogo();
		Carta *escolhida;
		Carta *carta_atual =  pilha_de_cartas.back();
		std::cout << "Carta atual :  " ;
		carta_atual->print_carta();


		if (jogadores[ jogador_atual ] ->cartas_jogaveis(carta_atual) == 0 ){
			std::cout << jogadores[ jogador_atual ]->get_nome() <<" NAO POSSUI CARTAS PARA JOGAR E TEVE COMPRAR UMA " << std::endl;
			jogadores[ jogador_atual ]->compra_carta(*baralho);
			this->passa_rodada();
			return 1;
		}
		else if (carta_atual->get_valor() == COMPRA_2 && jogadores[this->jogador_atual]->qtd_compra_2() > 0 && carta_atual->get_jogador_alvo() == jogador_atual){
			escolhida = jogadores[jogador_atual]->rebate_compra_2();
		}
		else if (carta_atual->get_valor() == COMPRA_4   && jogadores[this->jogador_atual]->qtd_compra_4() > 0 && carta_atual->get_jogador_alvo() == jogador_atual){
			escolhida = jogadores[jogador_atual]->rebate_compra_4();
		} 
		else{
			escolhida = jogadores[ jogador_atual ]->jogada( carta_atual );
			
		}
		
		if(jogadores[jogador_atual]->num_cartas() == 0){
			std::cout << "Acabou "<<jogadores[jogador_atual]->get_nome() << " é o campeao" << std::endl;
			return 0;
		}
		pilha_de_cartas.push_back(escolhida);
		this->efeitos_de_carta(escolhida);
		this->passa_rodada();
		return 1;                                                                                         
	}
	void Jogo::efeitos_de_carta(Carta *escolhida){
		
		int proximo_jogador = (this->jogador_atual + this->sentido) % this->n_jogadores;
		if (proximo_jogador < 0)
			proximo_jogador += this->n_jogadores;
		
		switch (escolhida->get_valor()){		
				case PULAR :	
						this->jogador_atual = proximo_jogador;
	 				break;

	 			case REVERTER:
		 				if (n_jogadores == 2)
		 					this->jogador_atual = proximo_jogador;	
		 				else
		 					this->sentido = -sentido;
	 				break;

	 			case COMPRA_2:
						escolhida->set_jogador_alvo(proximo_jogador);
						if (jogadores[proximo_jogador]->qtd_compra_2() == 0 ){

							int n_compra_2 = this->cnt_compra_2();

							for(int i = 0;i <2*n_compra_2 ;i++)
				 				this->jogadores[proximo_jogador]->compra_carta(*baralho);
				 			this->jogador_atual = proximo_jogador;

						}
						else{}
	 				 break;

	 			case COMPRA_4:
	 					escolhida->set_jogador_alvo(proximo_jogador);
						if (jogadores[proximo_jogador]->qtd_compra_4() == 0 ){
							int n_compra_4 = this->cnt_compra_4();
							for(int i = 0;i < 4*n_compra_4;i++)
				 				this->jogadores[proximo_jogador]->compra_carta(*baralho);
				 			this->jogador_atual = proximo_jogador;
						}			 		
				 		escolhida->set_cor_coringa();
	 				break;

	 			case CORINGA:
	 					escolhida->set_cor_coringa();
	 				break;			 
		}
	}
	int Jogo::cnt_compra_2(){
		std::list<Carta*>::reverse_iterator rit = pilha_de_cartas.rbegin();
		int contador = 0;
		while ( (*rit)->get_valor()  == COMPRA_2 && rit!=pilha_de_cartas.rend() && (*rit)->get_jogador_alvo() != -1 ){
			contador = contador  + 1;
			(*rit)->set_jogador_alvo(-1);
			++rit;
		}
		//std::cout<< "QUANTIDADE DE CARTA +2 == " << contador <<std::endl;
		return contador;
	}
	int Jogo::cnt_compra_4(){
		std::list<Carta*>::reverse_iterator rit = pilha_de_cartas.rbegin();
		int contador = 0;
		while ( (*rit)->get_valor()  == COMPRA_4   && rit !=pilha_de_cartas.rend() && (*rit)->get_jogador_alvo() != -1){
			contador = contador  + 1;
			(*rit)->set_jogador_alvo(-1);
			++rit;
		}
		//std::cout<< "QUANTIDADE DE CARTA +4 == " << contador <<std::endl;
		return contador;
	}
	void Jogo::passa_rodada(){
		this->jogador_atual = (this->jogador_atual + this->sentido) % this->n_jogadores;			
		if (this->jogador_atual < 0)
			this->jogador_atual += this->n_jogadores;
			this->rodada++;
	}









			// int proximo_jogador = (jogador_atual + sentido) % n_jogadores ;
		// 	if (proximo_jogador < 0)
		// 		proximo_jogador += n_jogadores;
		//system("clear");
		//int proximo_jogador = 0;
			   //  if (rodada % 4 == 3)
	    	// system("clear");





	// if(carta_atual->get_valor() == COMPRA_2){
	// 			escolhida = jogadores[ jogador_atual ] ->rebate_compra_2(this->cnt_compra_2(),baralho);
	// 			if (escolhida != nullptr){
	// 				pilha_de_cartas.push_back(escolhida);
	// 				//this->efeitos_de_carta(escolhida);
	// 			}
	// 			else {
	// 				this->efeitos_de_carta(atual); 
	// 			}
	// 		}
	// 		else {
	// 			escolhida = jogadores[ jogador_atual ]->jogada( carta_atual );
	// 			pilha_de_cartas.push_back(escolhida);
	// 			this->efeitos_de_carta(escolhida); 
	// 		}




	// proximo_jogador = (this->jogador_atual + this->sentido) % this->n_jogadores;
	 				// if (proximo_jogador < 0)
						// proximo_jogador += this->n_jogadores;

	 				// for(int i = 0;i < 2;i++){
			 		// 	this->jogadores[proximo_jogador]->compra_carta(*baralho);
	 				// }




	// this->jogador_atual = (jogador_atual + sentido) % n_jogadores;
	// if (this->jogador_atual < 0)
	// 	this->jogador_atual += this->n_jogadores;


	//&& jogadores[ jogador_atual ]->num_cartas() > 0 