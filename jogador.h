#ifndef JOGADOR_H
#define JOGADOR_H 

#include <string>
#include <vector>
	
	class Carta;
	class Baralho;
	class Jogo;

	class Jogador{
		private:
			std::string nome;
			std::vector<Carta*> mao;
		public:
			Jogador();
			Jogador(std::string name);
			~Jogador();
			
			//METODOS
			std::string get_nome() const;
			void set_nome(std::string name);
			int num_cartas() const;	
			void compra_carta(Baralho &baralho);
			Carta* jogada (Carta *atual);
			void print_mao() const;
			int cartas_jogaveis(Carta *atual) const;
			int qtd_compra_2() const;
			int qtd_compra_4() const;
			Carta* rebate_compra_2();
			Carta* rebate_compra_4();
	};



#endif
