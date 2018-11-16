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
		this->print_mao();
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
			//primeiro  o ponteiroé  apontado para nullptr para que o metodo erase() nao apague o objeto alocado no heap  
			_mao[pos] = nullptr;
			_mao.erase(_mao.begin() + pos);
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
	int Jogador::qtd_compra_2() const{
		//retorna a quantidade de caratas +4 na mao de um jogador
		int  n_compra_2= 0;
		for (int i = 0;i < this->num_cartas();i++){
			if ( _mao[i]->get_valor() == COMPRA_2 ){
				n_compra_2++;
			}
		}
		return n_compra_2;
	}
	int Jogador::qtd_compra_4() const{
		//retorna a quantidade de caratas +2 na mao de um jogador
		int  n_compra_4= 0;
		for (int i = 0;i < this->num_cartas();i++){
			if ( _mao[i]->get_valor() == COMPRA_4   ){
				n_compra_4++;
			}
		}
		return n_compra_4;

	}
	Carta* Jogador::rebate_compra_2(){
	
			int tam = this->num_cartas();
			int pos = 0;
			
			std::cout << _nome << " : "<< std::endl;
			std::cout<<std::endl;
			
			for (int i = 0 ; i < tam ; i++){
				if(_mao[i]->get_valor() == COMPRA_2){	
					std::cout<< "  " << i << " ";
					_mao[i]->print_carta();
				}	
			}
			std::cout <<std::endl;	
			std::cout<<"Escolha a posicao da carta +2(COMPRA_2) de sua mao para jogar :" << std::endl;
			std::cin >> pos;
			
			//tratamento de entrada do usuario
			while( std::cin.fail() || pos < 0 || pos > this->num_cartas()-1 || _mao[pos]->get_valor() != COMPRA_2){
				if( std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(INT_MAX,'\n');
					std::cout<< "Jogada invalida carta inexistente. Jogue novamente"<<std::endl;
				}
				if (_mao[pos]->get_valor() != COMPRA_2){
					std::cout<<"Erro :a carta escolhida nao e uma carta +2 .Jogue novamente" << std::endl;
				}
				std::cin >> pos;
			}

			Carta *to_return = _mao[pos];
			_mao.erase(_mao.begin() + pos);
			return to_return;
	}
	Carta* Jogador::rebate_compra_4(){
			
			int tam = this->num_cartas();
			int pos = 0;
			
			std::cout << _nome << " : "<< std::endl;
			std::cout<<std::endl;
		
			for (int i = 0 ; i < tam ; i++){
				if(_mao[i]->get_valor() == COMPRA_4  ){	
					std::cout<< "  " << i << " ";
					_mao[i]->print_carta();
				}	
			}
			std::cout <<std::endl;	
			std::cout<<"Escolha a posicao da carta +4(COMPRA_4) de sua mao para jogar :" << std::endl;
			std::cin >> pos;
			
			//tratamento de entrada do usuario
			while( std::cin.fail() || pos < 0 || pos > this->num_cartas()-1 || _mao[pos]->get_valor() != COMPRA_4){
				if( std::cin.fail()){
					std::cin.clear();
					std::cin.ignore(INT_MAX,'\n');
					std::cout<< "Jogada invalida, carta inexistente. Jogue novamente"<<std::endl;
				}
				if (_mao[pos]->get_valor() !=COMPRA_4){
					std::cout<<"Erro :a carta escolhida nao e uma carta +4 .Jogue novamente" << std::endl;
				}
				std::cin >> pos;
			}
			Carta *to_return = _mao[pos];		

			_mao.erase(_mao.begin() + pos);
			return to_return;
	}
	
	
