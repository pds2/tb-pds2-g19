#include <list>

//onde se joga as cartas
//primeiramente eu usei o stack mas acabei mudando para list pois e mais facil de lidar  
#ifndef JOGO_H
#define JOGO_H
	
	class Baralho;
	class Carta;
	class Jogador;


	class Jogo{
		private:
			std::list <Carta*> Jogo_cartas;
			std::vector <Jogador*> jogadores;
			int sentido = 1;
		public:
			Jogo();
			~Jogo();
			//METODOS
			int get_tamanho() const;
			void re_embaralhar(Baralho &b);
			void print_Jogo (); 
			//void set_jogador_atual(Jogador *a);
			void inserir_fim(Carta *a);
			void inserir_jogador()


	};


#endif 
