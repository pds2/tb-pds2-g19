#include <list>

//onde se joga as cartas
//primeiramente eu usei o stack mas acabei mudando para list pois e mais facil de lidar  
#ifndef PILHA_H
#define PILHA_H
	
	class Baralho;
	class Carta;
	class Jogador;


	class Pilha{
		private:
			std::list <Carta*> pilha_cartas;
			Jogador *atual;
		public:
			Pilha();
			~Pilha();
			//METODOS
			int get_tamanho() const;
			void re_embaralhar(Baralho &b);
			void print_pilha ();
			void set_jogador_atual(Jogador *a);

	};


#endif 
