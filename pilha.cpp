#include "pilha.h"


	Pilha::Pilha(){}
	Pilha::~Pilha(){}
	//METODOS
	int Pilha::get_tamanho() const{
		return pilha_cartas.size();
	}
	void Pilha::re_embaralhar(Baralho &b){}
	void Pilha::print_pilha(){
		std::list<Carta*>::iterator it  = pilha_cartas.end();
		for (it;it != pilha_cartas.begin();it--)
			(*it)->print_carta();	
	}