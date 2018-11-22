#include <iostream>
#include "jogador.h"
#include "carta.h"
#include "jogo.h"
#include "baralho.h"
#include "bot.h"

  Bot::Bot(int numero):Jogador("Bot0" + std::to_string(numero)){}
  //Bot::~Bot(){}
  Carta* Bot::jogada (Carta *atual){
    for(int i=0;i<this->num_cartas();i++){
      if(_mao[i]->get_cor()==atual->get_cor()||_mao[i]->get_cor()==ESPECIAL)
    }
  }
  //Carta* Bot::rebate(char valor){}
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
    escolhida->set_cor(cor);
  }
  bool Bot::vai_jogar(){return true;}
