#include "carta.h"

	Carta::Carta(){}
	Carta::Carta(std::string color , std::string value){
		cor = color;
		valor = value;
	}
	Carta::~Carta(){}
	//METODOS
	std::string Carta::get_cor() const{
		return cor;
	}
	std::string Carta::get_valor() const{
		return valor;
	}