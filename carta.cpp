	#include <iostream>
#include "carta.h"
#include "baralho.h"

	Carta::Carta(){}
	Carta::Carta(char color , char value){
		cor = color;
		valor = value;
		jogador_alvo = -1;
	}
	Carta::~Carta(){}
	
	//METODOS

	char Carta::get_cor() const{
		return cor;
	}
	char Carta::get_valor() const{
		return valor;
	}
	
	void Carta::set_cor_coringa(){
		//metodo destinado asa carta que o jogador pode escolher  a cor
		char c;
		if (cor == ESPECIAL){
			std::cout << " Escolha a cor que deseja : " << std::endl;
			std::cin >> c;
			cor = c;
		}
	}
	void Carta::print_carta() const{
	
		switch (this->cor){
		 	
		 	case RED:
		 		std::cout << "  red   ";
		 		break;

		 	case YELLOW:
		 		std::cout << " yellow ";
		 		break;

		 	case BLUE:
		 		std::cout << "  blue  ";
		 		break;

		 	case GREEN:
		 		std::cout << "  green  ";
		 		break;

		 	case ESPECIAL:
		 		std::cout << "  especial ";
		 		break;
		}
		switch (this->valor){
			
			case PULAR:
				std::cout << " pular";
				break;

			case REVERTER:
				std::cout << " reverter  ";
				break;

			case COMPRA_2:
				std::cout << " compra 2  " ;
				break;

			case COMPRA_4  :
				std::cout << " compra 4 " ;
				break;

			case CORINGA:
				std::cout << " coringa  " ;
				break;

			default :
				std::cout << " " << valor << " " ;
				break;

		}
		std::cout << std::endl; 
	}
		
int Carta::get_jogador_alvo() const{
	return this->jogador_alvo;
}
void Carta::set_jogador_alvo(int pos){
	this->jogador_alvo = pos;
}