#include <iostream>
#include <limits.h>

#include "carta.h"
#include "baralho.h"

#include "excecoes.h"

	//CONSTRUTOR E DESTRUTOR

	Carta::Carta(){}
	
	Carta::Carta(char cor,char valor){
		if(!carta_valida(cor,valor)) 
			throw CartaInvalidaException();
		else {
			_cor = cor;
			_valor = valor;
			_jogador_alvo = -1;
		}
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
		if(cor != RED && cor != BLUE && cor != GREEN && cor != YELLOW ) throw CartaInvalidaException();
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
		 		std::cout << "Essa cor nao possivel ";		 		
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

	bool Carta::carta_valida(char cor,char valor){
		char cartas_validas_valor[]= {'0','1','2','3','4','5','6','7','8','9',COMPRA_2,REVERTER,PULAR};
		char cores_validas[] = {RED,YELLOW,GREEN,BLUE};
		char cartas_validas_especiais_valor[] = {CORINGA,COMPRA_4};//tem que ter a cor ESPECIAL
		char cor_especial = ESPECIAL;

		for (int i : cartas_validas_valor)
			if (valor == i)
				for(int j : cores_validas)
					if(cor == j)
						return true;
				
		for(int i : cartas_validas_especiais_valor)
			if (valor == i && cor == cor_especial)
				return true;

		return false;
	}