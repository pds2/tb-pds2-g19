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
			std::list <Carta*> _pilha_de_cartas;
			std::vector <Jogador*> _jogadores;
			Baralho * _baralho;
			int _sentido;
			int _jogador_atual;
			int _n_jogadores;
			int _n_bots;
			
		public:
			Jogo();
			~Jogo();
			//METODOS
			int get_tamanho() const;
			void print_Jogo (); 
			int rodada();
			void efeitos_de_carta(Carta *atual);

			// int cnt_compra_2();
			// int cnt_compra_4();
			int cnt_de_carta(char valor);
			
			void passa_rodada();
			void repoe_baralho();

			void inicia_jogo();
		
			


	};


#endif 
