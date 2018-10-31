#include <iostream>
#include <cstdlib>
#include "carta.h"
#include "baralho.h"


	//CONSTRUTOR E DESTRUTOR
	
	Baralho::Baralho(){
		Carta *ptr1;

		char cores[4] = { RED , YELLOW , BLUE , GREEN };
		char especiais_com_cores[3] = { PULAR , REVERTER , COMPRA_2 };
		char especiais[2] = { COMPRA_4   , CORINGA };

		for (int i = 0; i < 4;i++){
			
			for(int j = 0; j < 10;j++){
				ptr1 = new Carta(cores[i],j + 48);
				baralho.push_back(ptr1);

			}

			for(int j = 1; j < 10;j++){
				ptr1 = new Carta(cores[i],j + 48);
				baralho.push_back(ptr1);

			}
			for(int j = 0; j < 3;j++){
				ptr1 = new Carta(cores[i],especiais_com_cores[j]);
				baralho.push_back(ptr1);

			}
			for(int j = 0; j < 3;j++){
				ptr1 = new Carta(cores[i],especiais_com_cores[j]);
				baralho.push_back(ptr1);

			}	

		}
		for (int i = 0; i < 2;i++){
			for(int j = 0; j < 4;j++){
				ptr1 = new Carta(ESPECIAL,especiais[i]);
				baralho.push_back(ptr1);

			}
		}
		this->embaralhar();
	}
	Baralho::~Baralho(){
		 while (!baralho.empty()){
		 	  delete baralho[baralho.size() - 1];
		 	  baralho.pop_back();
		 }
	}

	//METODOS

	int Baralho::get_tamanho() const{
		return baralho.size();
	}
	
	
	void Baralho::embaralhar(){
		//The modern algorithm of Fisher–Yates shuffle para embaralhar 
		//LINK : https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
		srand (time(NULL));
		int j = 0;
		Carta *aux;
		for (int i = baralho.size() - 1;i > 1;i--){
			j = rand() % (i + 1);
			aux = baralho[j];
			baralho[j] = baralho[i];
			baralho[i] = aux;
		}
	}
	
	void Baralho::print_baralho() const{
		int tam = this->get_tamanho();
		for (int i = 0;i < tam;i++){
			std::cout << i << " ";
			baralho[i]->print_carta();
		}
	}
	void Baralho::remove_fim(){
		baralho[baralho.size() - 1] = nullptr;
		baralho.pop_back();
	}
	Carta* Baralho::get_ultima_carta(){
		return baralho[baralho.size() - 1];
	}
	void Baralho::retira_especial_do_topo(){
		//caso a primeira carta seja uma carta de efeito o bralho sera rebaralhado,
		//nao é a soluçao mais elegante (inclusive pode fazer com ele seja embaralhado varias vezes mas funciona)
		while(baralho.back()->get_valor()== PULAR || baralho.back()->get_valor()== REVERTER || baralho.back()->get_valor()== COMPRA_2 || baralho.back()->get_cor()== ESPECIAL ){
			this->embaralhar();
		}
	}

