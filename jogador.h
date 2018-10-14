#ifndef JOGADOR_H
#define JOGADOR_H 

#include <string>
#include <vector>
#include "carta.h"
#include "pilha.h"
	
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
			void jogada (Carta *carta_jogada,Pilha &pilha);
			void print_mao() const;
	};



#endif
