#include <stack>
#include "carta.h"
#include "baralho.h"

//onde se joga as cartas

#ifndef PILHA_H
#define PILHA_H
	

	class Pilha{
		private:
			std::stack <Carta> pilha_cartas;
		public:
			Pilha();
			~Pilha();
			//METODOS
			int get_tamanho() const;
			void re_embaralhar(Baralho &b);

	};


#endif 