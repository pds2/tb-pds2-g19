#ifndef BOT_H
#define BOT_H 
#include "jogador.h"
	


	class Bot : public Jogador {
		public:
			Bot(std::string nome);
			~Bot();
			virtual Carta* jogada (Carta *atual) override;
			virtual Carta* rebate(char valor) override;
			
	};


#endif