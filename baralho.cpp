#include <iostream>
#include <cstdlib>
#include <time.h>

#include "carta.h"
#include "baralho.h"

#define N_CORES 4
#define N_VALORES 10
#define N_ESPECIAIS_COLORIDAS 3
#define N_ESPECIAIS 4

	//CONSTRUTOR E DESTRUTOR
	
	Baralho::Baralho(){
		Carta *ptr1,*ptr2;

		char cores[4] = { RED , YELLOW , BLUE , GREEN };
		char especiais_com_cores[3] = { PULAR , REVERTER , COMPRA_2 };
		char especiais[2] = { COMPRA_4   , CORINGA };
		//incliuindo carta com cores 
		for (int i = 0; i < N_CORES ;i++){
			//incluindo valores de 0 a 9
			for(int j = 0; j < N_VALORES;j++){
				ptr1 = new Carta(cores[i],j + 48);
				baralho.push_back(ptr1);

			}
			//incluindo valores de 1 a 9
			for(int j = 1; j < N_VALORES;j++){
				// (j + 48) TRANFORMANDO INTEIRO EM ASCII
				ptr1 = new Carta(cores[i],j + 48);
				baralho.push_back(ptr1);

			}
			//iNCLUINDO PULAR REVERTER COMPRA_2	 X2
			for(int j = 0; j < N_ESPECIAIS_COLORIDAS;j++){
				ptr1 = new Carta(cores[i],especiais_com_cores[j]);
				baralho.push_back(ptr1);
				ptr2 = new Carta(cores[i],especiais_com_cores[j]);
				baralho.push_back(ptr2);

			}
		}
		//INCLUINDO  8 ESPECIAS COMPRA_4 CORINGA 
		for (int i = 0; i < 2;i++){
			for(int j = 0; j < N_ESPECIAIS;j++){
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
		//LINK : 	
		srand (time(NULL));
		int j = 0;
		Carta *aux;
		for (int i = baralho.size() - 1;i > 1;i--){
			j = rand() % (i + 1);
			//troca carta da posicão i com j  
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
	//////////
	void Baralho::adiciona_carta(Carta& carta){
		baralho.push_back(&carta);
	}
	//////////
