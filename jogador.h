#include <string>
#include <vector>
#include "carta.h"


#ifndef JOGADOR_H
#define JOGADOR_H 
	
	class Jogador{
		private:
			std::string nome;
			std::vector<Carta> mao;
		public:
			Jogador();
			Jogador(std::string name);
			~Jogador();
			//METODOS
			std::string get_nome() const;
			int get_cartas() const;		
	};



#endif