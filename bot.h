#ifndef BOT_H
#define BOT_H 
#include "jogador.h"
	


	class Bot : public Jogador {
		public:
			Bot(std::string nome);
			~Bot();
			virtual Carta* jogada (Carta *atual);
			virtual Carta* rebate_compra_2();
			virtual Carta* rebate_compra_4();	
	};


#endif