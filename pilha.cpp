#include "pilha.h"
#include "carta.h"
#include "baralho.h"


	Pilha::Pilha(){}
	
	Pilha::~Pilha(){
		 while (!pilha_cartas.empty()){
		 	  delete pilha_cartas.front();
		 	  pilha_cartas.pop_front();
		 }
	}
	//METODOS
	int Pilha::get_tamanho() const{
		return pilha_cartas.size();
	}

	void Pilha::re_embaralhar(Baralho &b){}

	void Pilha::print_pilha(){
		//std::list<Carta*>::iterator it  = pilha_cartas.end();
		for (std::list<Carta*>::reverse_iterator rit = pilha_cartas.rbegin(); rit!=pilha_cartas.rend(); ++rit)
			(*rit)->print_carta();	
	}

	void  Pilha::set_jogador_atual(Jogador *a){
		this->atual = a;
	}
	void Pilha::inserir_fim(Carta *a){
		pilha_cartas.push_back(a);
	}