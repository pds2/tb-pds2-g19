#include <string>
#include <vector>

#ifndef BARALHO_H
#define BARALHO_H

	class Carta;
	class Baralho{
		private:
			std::vector<Carta*> baralho;
		public:
			//CONTRUTOR E DESTRUTOR
			Baralho();
			~Baralho();
			
			//METODOS
			int get_tamanho() const;
			void embaralhar();
			void print_baralho() const;
			void remove_fim();
			Carta* get_ultima_carta();
			void retira_especial_do_topo();
			//////////
			void adiciona_carta(Carta& carta);
			//////////
	};
	

#endif 
