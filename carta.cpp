	#include <iostream>
#include "carta.h"
#include "baralho.h"

	Carta::Carta(){}
	Carta::Carta(char color , char value){
		_cor = color;
		_valor = value;
		_jogador_alvo = -1;
	}
	Carta::~Carta(){}
	
	//METODOS

	char Carta::get_cor() const{
		return _cor;
	}
	char Carta::get_valor() const{
		return _valor;
	}
	
	void Carta::set_cor_coringa(){
		//metodo destinado asa carta que o jogador pode escolher  a cor
		char c;
		if (this->_cor == ESPECIAL){
			std::cout << " Escolha a cor que deseja : (r,b,g,y)" << std::endl;
			std::cin >> c;
			//TRATAR EXCECOES DE ERRO DE USUARIO 

			this->_cor = c;
		}
	}
	void Carta::print_carta() const{
	
		switch (this->_cor){
		 	
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
		 	default : 
		 		std::cout << " ERRO ERRO COR NAO POSSIVEL ";		 		
		}
		switch (this->_valor){
			
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
				std::cout << " " << _valor << " " ;

		}
		std::cout << std::endl; 
	}
		
int Carta::get_jogador_alvo() const{
	return this->_jogador_alvo;
}
void Carta::set_jogador_alvo(int pos){
	this->_jogador_alvo = pos;
}