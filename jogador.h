#ifndef JOGADOR_H
#define JOGADOR_H 

#include <string>
#include <vector>
	
	class Carta;
	class Baralho;
	class Pilha;

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
			int num_cartas() const;	
			void compra_carta(Baralho &baralho);
			void jogada (int pos,Pilha &pilha);
			void print_mao() const;

	};



#endif
