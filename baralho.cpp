#include "baralho.h"


	Baralho::Baralho(){
		Carta *ptr;
		std::string cores[4]{"vermelho","amarelo","verde","azul"};
		for (int i = 0; i < 4;i++){
			for(int j = 0; j < 10;j++){
				ptr = new Carta(cores[i],std::to_string(j));
				baralho.push_back(ptr);
			}
		}

	}
	Baralho::~Baralho(){}
	//METODOS
	int Baralho::get_tamanho() const{
		return baralho.size();
	}
	void Baralho::embaralhar(){}
	void Baralho::print_baralho() const{}



