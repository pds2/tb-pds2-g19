#include <list>
#include <vector>
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
			int get_sentido() const;
			int get_jogador_atual() const;
			int get_n_jogadores() const;
			Carta* get_carta_atual() const;
			Jogador* get_jogador(int n) const;
			void print_Jogo ();
			int rodada();
			void efeitos_de_carta(Carta *atual);
			int cnt_de_carta(char valor);
			void passa_rodada();
			void repoe_baralho();
			void inicia_jogo();

			void randomizar_jogadores();

			void inicializa_jogadores();
			int efeito_compra(char valor,int jogador);
			void print_carta_atual();
	};


#endif
