#include <string>
#include <vector>
#include "carta.h"


#ifndef BARALHO_H
#define BARALHO_H


	class Baralho{
		private:
			std::vector<Carta*> baralho;
		public:
			Baralho();
			~Baralho();
			//METODOS
			int get_tamanho() const;
			void embaralhar();
			void print_baralho() const;	
	};
	

#endif 