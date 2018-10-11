#include <string>

#ifndef CARTA_H
#define CARTA_H

class Carta{

	private:
		std::string cor;
		std::string valor;
	public:
		Carta();
		Carta(std::string color , std::string value);
		~Carta();
		//METODOS
		std::string get_cor() const;
		std::string get_valor() const;
};



#endif