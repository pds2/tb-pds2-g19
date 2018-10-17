#include <string>

#ifndef CARTA_H
#define CARTA_H


#define red      'r'
#define yellow   'y'
#define blue     'b'
#define green    'g'
#define especial 'e'

#define pular    '@'
#define reverter '#'
#define compra_2 '$'

#define compra_4 '%'
#define coringa  '&'
	


class Carta{

	private:
		char cor;
		char valor;
	public:
		Carta();
		Carta(char color , char	 value);
		~Carta();
		//METODOS
		char get_cor() const;
		char get_valor() const;
		void print_carta() const;
};



#endif