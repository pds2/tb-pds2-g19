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
		int sentido = this->_jogo->get_sentido();
		int jogador_atual = this->_jogo->get_jogador_atual();
		int n_participantes =  this->_n_bots + this->_jogo->get_n_jogadores();

		int pos_proximo_jogador = (jogador_atual + sentido)% n_participantes;
		
		if(pos_proximo_jogador  < 0)
			pos_proximo_jogador += n_participantes;
		Jogador *proximo_jogador = this->_jogo->get_jogador(pos_proximo_jogador);

		Carta *to_return;
		to_return = nullptr;
		if (proximo_jogador->num_cartas() <= 5){
			to_return = this->atrapalha_proximo(atual);
			if(to_return != nullptr )
				return to_return;
		}
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
	Carta *Bot::atrapalha_proximo(Carta *atual){
			
		Carta *to_return[8] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

		if (this->qtd_de_carta(COMPRA_2) > 0)
			if (atual->get_valor() == COMPRA_2)
				to_return[0] = this->escolhe_carta(COMPRA_2);
		
		if (this->qtd_de_carta(COMPRA_4 ) > 0)
			if (atual->get_valor() == COMPRA_4)
				to_return[1] =this->escolhe_carta(COMPRA_4);
		
		if (this->qtd_de_carta(PULAR)>  0)
			if (atual->get_valor() == PULAR)
				to_return[2] =	this->escolhe_carta(PULAR);
		
		if ((this->qtd_de_carta(REVERTER) > 0 )&& (_n_bots + _jogo->get_n_jogadores() > 2) )
			if (atual->get_valor() == REVERTER )
				to_return[3] =  this->escolhe_carta(REVERTER);
		
		if (this->qtd_de_carta(COMPRA_2) > 0)to_return[4] = this->escolhe_carta(COMPRA_2,atual->get_cor());
		if (this->qtd_de_carta(COMPRA_4) > 0)to_return[5] = this->escolhe_carta(COMPRA_4,atual->get_cor()); 
		if (this->qtd_de_carta(PULAR)> 0)to_return[6] = this->escolhe_carta(PULAR,atual->get_cor());
		if ((this->qtd_de_carta(REVERTER) > 0) && ( _n_bots + _jogo->get_n_jogadores() > 2))to_return[7] = this->escolhe_carta(REVERTER,atual->get_cor());

		for (int i = 0; i < 8;i++){
			if (to_return[i] != nullptr){
				this->tira_carta_mao(to_return[i]);
				return to_return[i];
			}
		}
		return nullptr;
	}
	Carta *Bot::escolhe_carta(char valor){
		Carta *to_return;
		for(int i=0;i<this->num_cartas();i++){
			if( _mao[i]->get_valor() == valor ){
				to_return = _mao[i];
				std::cout << "O " << this->get_nome() << " jogou : ";
				to_return->print_carta();
				//std::this_thread::sleep_for(std::chrono::seconds(2));
				return to_return;
			}
		}
		return nullptr;
	}
	Carta *Bot::escolhe_carta(char valor,char cor){
		Carta *to_return;
		for(int i=0;i<this->num_cartas();i++){
			if((_mao[i]->get_valor() == valor  && _mao[i]->get_cor() == cor) || (_mao[i]->get_valor() == valor && valor == CORINGA)  || (_mao[i]->get_valor() == valor && valor == COMPRA_4) ){
				to_return = _mao[i];
				std::cout << "O " << this->get_nome() << " jogou : ";
				to_return->print_carta();
				//std::this_thread::sleep_for(std::chrono::seconds(2));
				return to_return;
			}
		}
	}
	void  Bot::tira_carta_mao(Carta *escolhida){
		for (int i = 0;i < this->num_cartas() ; i++)
			if (_mao[i] == escolhida){
				_mao.erase(_mao.begin() + i);
				break;
			}
	}