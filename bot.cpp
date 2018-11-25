#include <iostream>
#include <chrono>
#include <thread>
#include "jogador.h"
#include "carta.h"
#include "jogo.h"
#include "baralho.h"
#include "bot.h"

	int Bot::_n_bots = 0;

	Bot::Bot(Jogo *jogo):Jogador("Bot0" + std::to_string(1 + _n_bots++)){
		_jogo = jogo;
	}

	Carta* Bot::jogada (Carta *atual){
		//std::this_thread::sleep_for(std::chrono::seconds(2));
		Carta *to_return;
		for(int i=0;i<this->num_cartas();i++){
			if(_mao[i]->get_cor() == atual->get_cor() || _mao[i]->get_valor() == atual->get_valor() ||_mao[i]->get_cor()==ESPECIAL ){
				to_return = _mao[i];
				_mao.erase(_mao.begin() + i);
				std::cout << "O " << this->get_nome() << " jogou : ";
				to_return->print_carta();
				//std::this_thread::sleep_for(std::chrono::seconds(2));
				return to_return;
			}
		}
	}
	Carta* Bot::rebate(char valor){
		//std::this_thread::sleep_for(std::chrono::seconds(3));
		Carta *to_return;
		for(int i=0;i<this->num_cartas();i++){
			if(_mao[i]->get_valor() == valor ){
				to_return = _mao[i];
				_mao.erase(_mao.begin() + i);
				std::cout << "O " << this->get_nome() << " jogou : ";
				to_return->print_carta();
				//std::this_thread::sleep_for(std::chrono::seconds(3));
				return to_return;
			}
		}
		return nullptr;
	}
	void Bot::escolhe_cor(Carta *escolhida){
		char cor;
		int n_red=0;
		int n_blue = 0;
		int n_green = 0;
		int n_yellow = 0;

		for(int i=0;i<this->num_cartas();i++){
			if(_mao[i]->get_cor()==RED)n_red++;
			if(_mao[i]->get_cor()==BLUE)n_blue++;
			if(_mao[i]->get_cor()==GREEN)n_green++;
			if(_mao[i]->get_cor()==YELLOW)n_yellow++;
		}
		if(n_red>=n_blue&&n_red>=n_green&&n_red>=n_yellow)cor = RED;
		if(n_blue>=n_red&&n_blue>=n_green&&n_blue>=n_yellow)cor = BLUE;
		if(n_green>=n_blue&&n_green>=n_red&&n_green>=n_yellow)cor = GREEN;
		if(n_yellow>=n_blue&&n_yellow>=n_green&&n_yellow>=n_red)cor = YELLOW;
		Carta collor(cor,cor);
		std::cout << "O " << this->get_nome() << " escolheu : ";
		collor.print_carta_cor();
		//std::this_thread::sleep_for(std::chrono::seconds(1));

		escolhida->set_cor(cor);
	}
	bool Bot::vai_jogar(){return true;}
