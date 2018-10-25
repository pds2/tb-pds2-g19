#include <iostream>
#include "jogador.h"
#include "carta.h"
#include "jogo.h"
#include "baralho.h"

	Jogador::Jogador(){}
	Jogador::Jogador(std::string name){
		nome = name;
	}
	Jogador::~Jogador(){
		for(unsigned int i = 0;i < mao.size() ;i++){
			delete mao[mao.size() - 1];
			mao.pop_back();
		}
	}
	//METODOS
	std::string Jogador::get_nome() const{
		return nome;
	}
	void Jogador::set_nome(std::string name){
		nome = name;
	}
	int Jogador::num_cartas() const{
		return mao.size();
	}
	void Jogador::compra_carta(Baralho &baralho){
		if(baralho.get_tamanho() > 0 ){			
			mao.push_back(baralho.get_ultima_carta());
			baralho.remove_fim();
		}
	}

	Carta* Jogador::jogada (Carta *atual){
		std::cout<<"Escolha a posicao da carta de sua mao para jogar :" << std::endl;
		this->print_mao();
		unsigned int pos;
		std::cin >> pos;
		
		Carta *to_return = mao[pos];
		
		if (to_return->get_cor() == especial || to_return->get_cor() == atual->get_cor() || to_return->get_valor() == atual->get_valor()){
			mao[pos] = nullptr;
			mao.erase(mao.begin() + pos);
			return to_return;
		}
		else{
			std::cout<<"ERRRO carta errada" << std::endl;
			return this->jogada(atual);
		}
	}
	
	void Jogador::print_mao() const	{
		int tam = this->num_cartas();
		std::cout << nome << " : "<< std::endl;
		for (int i = 0 ; i < tam ; i++)
			mao[i]->print_carta();
		std::cout <<std::endl;
	}
