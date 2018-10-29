	#include <iostream>
#include "carta.h"
#include "baralho.h"

	Carta::Carta(){}
	Carta::Carta(char color , char value){
		cor = color;
		valor = value;
	}
	Carta::~Carta(){}
	//METODOS
	char Carta::get_cor() const{
		return cor;
	}
	char Carta::get_valor() const{
		return valor;
	}
	void Carta::print_carta() const{
	
		switch (this->cor){
		 	
		 	case red:
		 		std::cout << "  red   ";
		 		break;

		 	case yellow:
		 		std::cout << "  yellow ";
		 		break;

		 	case blue:
		 		std::cout << "  blue  ";
		 		break;

		 	case green:
		 		std::cout << "  green  ";
		 		break;

		 	case especial:
		 		std::cout << "  especial ";
		 		break;
		}
		switch (this->valor){
			
			case pular:
				std::cout << " pular";
				break;

			case reverter:
				std::cout << " reverter  ";
				break;

			case compra_2:
				std::cout << " compra 2  " ;
				break;

			case compra_4:
				std::cout << " compra 4 " ;
				break;

			case coringa:
				std::cout << " coringa  " ;
				break;

			default :
				std::cout << " " << valor << " " ;
				break;

		}
		std::cout << std::endl; 
	}
		
	void Carta::set_cor_coringa(){
		char c;
		if (cor == especial){
			std::cout << " Escolha a cor que deseja : " << std::endl;
			std::cin >> c;
			cor = c;
		}
	}






		// std::cout << cor ;

		// std::cout << valor << " " ;

	