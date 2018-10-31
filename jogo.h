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
			int jogador_atual;
			unsigned int n_jogadores;
			unsigned int rodada;
		public:
			Jogo();
			~Jogo();
			//METODOS
			int get_tamanho() const;
			void print_Jogo (); 
			int f_rodada();
			void efeitos_de_carta(Carta *atual);
			int cnt_compra_2();
			int cnt_compra_4();
			void passa_rodada();
			


	};


#endif 
