#include <iostream>
#include "carta.h"
#include "baralho.h"

	

	Baralho::Baralho(){
		Carta *ptr1;

		char cores[4] = { red , yellow , blue , green };
		char especiais_com_cores[3] = { pular , reverter , compra_2 };
		char especiais[2] = { compra_4 , coringa };

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
				ptr1 = new Carta(especial,especiais[i]);
				baralho.push_back(ptr1);
			}
		}
		
	}
	Baralho::~Baralho(){}
	
	//METODOS
	int Baralho::get_tamanho() const{
		return baralho.size();
	}
	
	void Baralho::embaralhar(){
		srand (time(NULL));
		//The modern algorithm of Fisher–Yates shuffle para embaralhar https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
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


