#include <iostream>
#include "carta.h"
#include "baralho.h"
#include <limits.h>

	//CONSTRUTOR E DESTRUTOR

	Carta::Carta(){}
	
	Carta::Carta(char cor,char valor){
		if(cor != "RED" && cor != "BLUE" && COR != "GREEN" && cor != "YELLOW" && cor != "ESPECIAL") throw CartaInvalidaException();
		if(valor != "0" && valor != "1" && valor != "2" && valor != "3" && valor != "4" && valor != "5" && valor != "6" && valor != "7" && valor != "8" && valor != "9" && ) throw CartaInvalidaException();
		
		_cor = cor;
		_valor = valor;
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
	
	void Carta::set_cor(char cor){
		if(cor != "RED" && cor != "BLUE" && COR != "GREEN" && cor != "YELLOW" && cor != "ESPECIAL") throw CartaInvalidaException();
		this->_cor = cor;
	}
	
	void Carta::print_carta_valor() const{
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
	}
	
	void Carta::print_carta_cor() const{
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
		 		std::cout << " ERRO COR NAO POSSIVEL ";		 		
		}
	}

	void Carta::print_carta() const{
		this->print_carta_cor();
		this->print_carta_valor();
		std::cout << std::endl; 
	}

	int Carta::get_jogador_alvo() const{
		return this->_jogador_alvo;
	}

	void Carta::set_jogador_alvo(int pos){
		this->_jogador_alvo = pos;
	}

	void Carta::tira_cor_especial(){
			//quando o baralho for reembaralhado as cartas especiais devem ter suas cores voltadas para ESPECIAL
			if ((_valor == CORINGA || _valor == COMPRA_4) && _cor != ESPECIAL )
				_cor = ESPECIAL;
	}	