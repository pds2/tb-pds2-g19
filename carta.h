
#include <string>

#ifndef CARTA_H
#define CARTA_H

#define RED      'r'
#define YELLOW   'y'
#define BLUE     'b'
#define GREEN    'g'
#define ESPECIAL 'e'

#define PULAR    '@'
#define REVERTER '#'
#define COMPRA_2 '$'


#define CORINGA  '%'
#define COMPRA_4 '*'
	


class Carta{

	private:
		char _cor;
		char _valor;
		int _jogador_alvo;
	public:
		//CONTRUTORES E DESTRUTOR 
		Carta();
		Carta(char cor,char valor);
		~Carta();
		
		//METODOS
		
		char get_cor() const;
		char get_valor() const;
		void set_cor(char cor);
		
		void print_carta() const;
		void print_carta_valor() const;
		void print_carta_cor() const;

		int get_jogador_alvo() const;
		void set_jogador_alvo(int pos);

		void tira_cor_especial();


};



#endif