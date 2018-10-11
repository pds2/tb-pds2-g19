#include "pilha.h"


	Pilha::Pilha(){}
	Pilha::~Pilha(){}
	//METODOS
	int Pilha::get_tamanho() const{
		return pilha_cartas.size();
	}
	void Pilha::re_embaralhar(Baralho &b){}
