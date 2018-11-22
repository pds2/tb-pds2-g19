#include <iostream>
#include "jogador.h"
#include "carta.h"
#include "jogo.h"
#include "baralho.h"
#include <limits.h>

	Jogador::Jogador(){}
	Jogador::Jogador(std::string nome){
		_nome = nome;
	}
	Jogador::~Jogador(){
		while(!_mao.empty()){
			delete _mao[_mao.size() - 1];
			_mao.pop_back();
		}
	}
	//METODOS
	std::string Jogador::get_nome() const{
		return _nome;
	}
	void Jogador::set_nome(std::string nome){
		_nome = nome;
	}
	int Jogador::num_cartas() const{
		return _mao.size();
	}
	void Jogador::compra_carta(Baralho &baralho){
		if(baralho.get_tamanho() > 0 ){
			_mao.push_back(baralho.get_ultima_carta());
			baralho.remove_fim();
		}
	}

	Carta* Jogador::jogada (Carta *atual){
		//retorna  o ponteiro da carta jogada pelo jogador
		std::cout<<"Escolha a posicao da carta de sua mao para jogar : " << std::endl;
		 int pos;
		std::cin >> pos;

		//EXECAO DE ENTRADA INVALIDA TRATADA
		while( std::cin.fail() || pos < 0 || pos > this->num_cartas()-1  ){
			if( std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(INT_MAX,'\n');
				std::cout<< "Jogada invalida "<<std::endl;
			}
			std::cout<<"A posicao escolhida nao existe, favor escolher entre 0 e " << this->num_cartas()-1 << std::endl;
			std::cin >> pos;
		}

		Carta *to_return = _mao[pos];

		if (to_return->get_cor() == ESPECIAL || to_return->get_cor() == atual->get_cor() || to_return->get_valor() == atual->get_valor()){
			//primeiro  o ponteiro é  apontado para nullptr para que o metodo erase() nao apague o objeto alocado no heap
			_mao[pos] = nullptr;
			_mao.erase(_mao.begin() + pos);
			std::cin.clear();
			return to_return;
		}
		else{
			std::cout<<"ERRO carta errada" << std::endl;
			return this->jogada(atual);
		}
	}

	void Jogador::print_mao() const	{
		int tam = this->num_cartas();
		std::cout << _nome << " : "<< std::endl;
		std::cout<<std::endl;
		for (int i = 0 ; i < tam ; i++){
			std::cout<< "  " << i << " ";
			_mao[i]->print_carta();
		}
		std::cout <<std::endl;
	}
	void Jogador::print_mao(char valor) const	{
		int tam = this->num_cartas();
		std::cout << _nome << " : "<< std::endl;
		std::cout<<std::endl;
		for (int i = 0 ; i < tam ; i++){
			if(_mao[i]->get_valor() == valor  ){
				std::cout<< "  " << i << " ";
				_mao[i]->print_carta();
			}
		}
		std::cout <<std::endl;
	}
	int Jogador::cartas_jogaveis(Carta *atual) const{
		//retorna a quantidade de cartas jogaveis pelo jogador tendo em base a carta jogada pelo ultimo jogador
		int n_cartas_jogaveis = 0;
		for (int i = 0;i < this->num_cartas();i++){
			if (_mao[i]->get_cor() == ESPECIAL || _mao[i]->get_cor() == atual->get_cor() || _mao[i]->get_valor() == atual->get_valor() ){
				n_cartas_jogaveis++;
			}
		}
		return n_cartas_jogaveis;
	}
	int Jogador::qtd_de_carta(char valor) const{
		int  cnt= 0;
		for (int i = 0;i < this->num_cartas();i++){
			if ( _mao[i]->get_valor() == valor   ){
				cnt++;
			}
		}
		return cnt;
	}
	Carta* Jogador::rebate(char valor){
		Carta value(' ',valor);
		int pos = 0;
		this->print_mao(valor);

		std::cout<<"Escolha a posicao da carta ";
		value.print_carta_valor();
		std::cout <<" de sua mao para jogar :" << std::endl;
		std::cin >> pos;
		//tratamento de entrada do usuario
		while( std::cin.fail() || pos < 0 || pos > this->num_cartas()-1 || _mao[pos]->get_valor() != valor){
			if( std::cin.fail()){
				std::cin.clear();
				std::cin.ignore(INT_MAX,'\n');
				std::cout<< "Jogada invalida, carta inexistente. Jogue novamente"<<std::endl;
			}
			if (_mao[pos]->get_valor() != valor){
				std::cout<<"Erro :a carta escolhida nao e uma ";
				value.print_carta_valor();
				std::cout <<" .Jogue novamente" << std::endl;
			}
			std::cin >> pos;
		}
		Carta *to_return = _mao[pos];
		_mao.erase(_mao.begin() + pos);
		return to_return;
	}
	void Jogador::escolhe_cor(Carta *escolhida){
		char cor;
		if (escolhida->get_cor() == ESPECIAL){
			std::cout << " Escolha a cor que deseja entre (r,b,g,y) : " << std::endl;
			std::cin >> cor;
			//EXCECAO DE ENTRADA INVALIDA TRATADA
			while(std::cin.fail() || (cor != 'r' && cor != 'b' && cor != 'g' && cor != 'y')){
				if( std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(INT_MAX,'\n');
				}
			  	std::cout << " Cor invalida escolhida, escolha entre (r,b,g,y) : " << std::endl;
				std::cin >> cor;
			}
			escolhida->set_cor(cor);
		}
		else{
			std::cout << "Programador : Tal carta nao pode mudar de cor durante a partida"<<std::endl;
		}
	}
  bool Jogador::vai_jogar(){
    char jogador_n_quer_jogar;
    std::cout << "Vc quer jogar('j') ou pular('p')?\n";
    std::cin >> jogador_n_quer_jogar;
    while(std::cin.fail()||(jogador_n_quer_jogar!='j'&&jogador_n_quer_jogar!='p')){
      if(std::cin.fail()){
         std::cin.clear();
         std::cin.ignore(INT_MAX,'\n');
      }
      std::cout << "Vc quer jogar('j') ou pular('p')?\n";
      std::cin >> jogador_n_quer_jogar;
    }
    if(jogador_n_quer_jogar=='p')return false;
    if(jogador_n_quer_jogar=='j')return true;
  }


