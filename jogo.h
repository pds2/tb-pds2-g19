#include <list>
#include <vector>

//onde se joga as cartas
//primeiramente eu usei o stack mas acabei mudando para list pois e mais facil de lidar  
#ifndef JOGO_H
#define JOGO_H
	
	class Baralho;
	class Carta;
	class Jogador;


	class Jogo{
		private:
			std::list <Carta*> pilha_de_cartas;
			std::vector <Jogador*> jogadores;
			Baralho *baralho;
			int sentido;
			unsigned int jogador_atual;
			unsigned int n_jogadores;
			unsigned int rodada;
		public:
			Jogo();
			~Jogo();
			//METODOS
			int get_tamanho() const;
			//void re_embaralhar(Baralho &b);
			void print_Jogo (); 
			//void set_jogador_atual(Jogador *a);
			//void inserir_fim(Carta *a);
			void f_rodada();
			


	};


#endif 
