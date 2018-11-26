#ifndef BOT_H
#define BOT_H
#include "jogador.h"



	class Bot : public Jogador {
		private:
			static int _n_bots;
			const Jogo* _jogo;
		public:
			Bot(Jogo *jogo);
			//~Bot();
			virtual Carta* jogada (Carta *atual) override;
			virtual Carta* rebate(char valor) override;
			virtual void escolhe_cor(Carta *escolhida) override;
			virtual bool vai_jogar() override;
			//char melhor_cor();
			Carta *atrapalha_proximo(Carta *atual);
			Carta *escolhe_carta(char valor);
			Carta *escolhe_carta(char valor,char cor);
			void  tira_carta_mao(Carta *escolhida);
	};


#endif
