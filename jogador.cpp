#include "jogador.h"

	Jogador::Jogador(){}
	Jogador::Jogador(std::string name){
		nome = name;
	}
	Jogador::~Jogador(){}
	//METODOS
	std::string Jogador::get_nome() const{
		return nome;
	}
	int Jogador::get_cartas() const{
		return mao.size();
	}
