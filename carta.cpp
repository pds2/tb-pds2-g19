#include <iostream>
#include "carta.h"
#include "baralho.h"
#include <limits.h>

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
		//metodo destinado as cartas que o jogador pode escolher  a cor
		char c;
		if (this->_cor == ESPECIAL){
			std::cout << " Escolha a cor que deseja entre (r,b,g,y) : " << std::endl;
			std::cin >> c;

			//EXCECAO DE ENTRADA INVALIDA TRATADA
			while(std::cin.fail() || (c != 'r' && c != 'b' && c != 'g' && c != 'y')){
				if( std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(INT_MAX,'\n');
				}
				std::cout << " Cor invalida escolhida, escolha entre (r,b,g,y) : " << std::endl;
				std::cin >> c;
			}

			this->_cor = c;
		}
		else {
			std::cout << "Programador : Tal carta nao pode mudar de cor durante a partida"<<std::endl;
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

void Carta::tira_cor_especial(){
		//Quando o baralho for reembaralhado as cartas especiais devem ter suas cores voltadas para ESPECIAL
		if ((_valor == CORINGA || _valor == COMPRA_4) && _cor != ESPECIAL )
			_cor = ESPECIAL;
}	