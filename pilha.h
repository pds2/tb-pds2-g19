#include <list>
#include "carta.h"
#include "baralho.h"

//onde se joga as cartas
//primeiramente eu usei o stack mas acabei mudando para list pois e mais facil de lidar  
#ifndef PILHA_H
#define PILHA_H
	
	class Pilha{
		private:
			std::list <Carta*> pilha_cartas;
		public:
			Pilha();
			~Pilha();
			//METODOS
			int get_tamanho() const;
			void re_embaralhar(Baralho &b);
			void print_pilha ();

	};


#endif 