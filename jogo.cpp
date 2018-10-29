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
	}
	//METODOS
	int Jogo::get_tamanho() const{
		return pilha_de_cartas.size();
	}

	//void Jogo::re_embaralhar(Baralho &b){}

	void Jogo::print_Jogo(){
		//std::list<Carta*>::iterator it  = pilha_de_cartas.end();
		for (std::list<Carta*>::reverse_iterator rit = pilha_de_cartas.rbegin(); rit!=pilha_de_cartas.rend(); ++rit)
			(*rit)->print_carta();	
	}

	// void  Jogo::set_jogador_atual(Jogador *a){
	// 	this->atual = a;
	// }
	// void Jogo::inserir_fim(Carta *a){
	// 	pilha_de_cartas.push_back(a);
	// }
	void Jogo::f_rodada(){
		system("clear");
		system("clear");
		Carta *carta_atual =  pilha_de_cartas.back();
		std::cout << "Carta atual : " << std::endl;
		carta_atual->print_carta();
		
		if (jogadores[ jogador_atual ] ->cartas_jogaveis(carta_atual) == 0 && jogadores[ jogador_atual ]->num_cartas() > 0 ){
			std::cout << "Voce nao possui cartas para jogar e teve comprar uma " << std::endl;
			jogadores[ jogador_atual ] ->compra_carta(*baralho);
		}
		else{
			if (jogadores[ jogador_atual ]->num_cartas() == 0 ){
				std::cout << "VOCE GANHOU " <<std::endl;
				return;
			}
			Carta *escolhida = jogadores[ jogador_atual ]->jogada( carta_atual );

			pilha_de_cartas.push_back(escolhida);



			int proximo_jogador = 0;
			switch (escolhida->get_valor()){
				case pular :
					jogador_atual = (jogador_atual + sentido) % n_jogadores;
	 				break;

	 			case reverter:
	 				sentido = -sentido;
	 				break;

	 			case compra_2:
	 				
	 				proximo_jogador = (jogador_atual + sentido) % n_jogadores;
	 				if (proximo_jogador < 0)
						proximo_jogador += n_jogadores;

	 				for(int i = 0;i < 2;i++){
			 			jogadores[proximo_jogador]->compra_carta(*baralho);
	 				}
	 				break;

	 			case compra_4 :
	 				
	 				proximo_jogador = (jogador_atual + sentido) % n_jogadores;
	 				if (proximo_jogador < 0)
						proximo_jogador += n_jogadores;

	 				for(int i = 0;i < 4;i++){
			 			jogadores[proximo_jogador]->compra_carta(*baralho);
	 				}
			 		escolhida->set_cor_coringa();
	 				break;

	 			case coringa:
	 				escolhida->set_cor_coringa();
	 				break;
				 
			}
			                   

		}
		jogador_atual = (jogador_atual + sentido) % n_jogadores;
			
		if (jogador_atual < 0)
			jogador_atual += n_jogadores;
			
		rodada++;                                                                                           
	}