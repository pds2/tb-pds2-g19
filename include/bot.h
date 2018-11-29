#include "jogador.h"

#ifndef BOT_H
#define BOT_H

	class Bot : public Jogador {
		private:
			static int _n_bots;
			const Jogo* _jogo;

		public:
			//CONTRUTOR E DESTRUTOR
			Bot(Jogo *jogo);
			~Bot();

			//METODOS
			virtual Carta* jogada (Carta *atual) override;
			virtual Carta* rebate(char valor) override;
			virtual void escolhe_cor(Carta *escolhida) override;
			virtual bool vai_jogar() override;
			virtual void print_mao() const override;
			virtual void print_mao(char valor) const override;
			Carta *atrapalha_proximo(Carta *atual);
			Carta *escolhe_carta(char valor);
			Carta *escolhe_carta(char valor,char cor);
			void  tira_carta_mao(Carta *escolhida);
	};

#endif