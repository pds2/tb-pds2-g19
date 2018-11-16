#ifndef JOGADOR_H
#define JOGADOR_H 

#include <string>
#include <vector>
	
	class Carta;
	class Baralho;
	class Jogo;

	class Jogador{
		protected:
			std::string _nome;
			std::vector<Carta*> _mao;
		public:
			Jogador();
			Jogador(std::string nome);
			~Jogador();
			
			//METODOS
			std::string get_nome() const;
			void set_nome(std::string nome);
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
