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
		//retorna  o ponteiro da carta jogada pelo jogador 
		std::cout<<"Escolha a posicao da carta de sua mao para jogar : " << std::endl;
		this->print_mao();
		unsigned int pos;
		std::cin >> pos;
		
		Carta *to_return = mao[pos];
		
		if (to_return->get_cor() == ESPECIAL || to_return->get_cor() == atual->get_cor() || to_return->get_valor() == atual->get_valor()){
			//primeiro  o ponteiroé  apontado para nullptr para que o metodo erase() nao apague o objeto alocado no heap  
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
		std::cout<<std::endl;
		for (int i = 0 ; i < tam ; i++){
			std::cout<< "  " << i << " ";
			mao[i]->print_carta();
		}
		std::cout <<std::endl;
	}
	int Jogador::cartas_jogaveis(Carta *atual) const{
		//retorna a quantidade de cartas jogaveis pelo jogador tendo em base a carta jogada pelo ultimo jogador
		int c_j = 0;
		for (int i = 0;i < this->num_cartas();i++){
			if (mao[i]->get_cor() == ESPECIAL || mao[i]->get_cor() == atual->get_cor() || mao[i]->get_valor() == atual->get_valor() ){
				c_j++;
			}
		}
		return c_j;
	}
	int Jogador::qtd_compra_2() const{
		//retorna a quantidade de caratas +4 na mao de um jogador
		int  n_compra_2= 0;
		for (int i = 0;i < this->num_cartas();i++){
			if ( mao[i]->get_valor() == COMPRA_2 ){
				n_compra_2++;
			}
		}
		return n_compra_2;
	}
	int Jogador::qtd_compra_4() const{
		//retorna a quantidade de caratas +2 na mao de um jogador
		int  n_compra_4= 0;
		for (int i = 0;i < this->num_cartas();i++){
			if ( mao[i]->get_valor() == COMPRA_4   ){
				n_compra_4++;
			}
		}
		return n_compra_4;

	}
	Carta* Jogador::rebate_compra_2(){
	
			int tam = this->num_cartas();
			int pos = 0;
			
			std::cout << nome << " : "<< std::endl;
			std::cout<<std::endl;
			
			for (int i = 0 ; i < tam ; i++){
				if(mao[i]->get_valor() == COMPRA_2){	
					std::cout<< "  " << i << " ";
					mao[i]->print_carta();
				}	
			}
			std::cout <<std::endl;	

			std::cout<<"Escolha a posicao da carta +2(COMPRA_2) de sua mao para jogar :" << std::endl;
			std::cin >> pos;
			Carta *to_return = mao[pos];
		    
		    //caso o usuario erre na digitaçao
			while (to_return->get_valor() != COMPRA_2){
				std::cout<<"ERRO ERRO ERRO ERRO escolha uma carta +2 :" << std::endl;
				std::cin >> pos;
				to_return = mao[pos];
			}

			mao[pos] = nullptr;
			mao.erase(mao.begin() + pos);
			return to_return;
	}
	Carta* Jogador::rebate_compra_4(){
			
			int tam = this->num_cartas();
			int pos = 0;
			
			std::cout << nome << " : "<< std::endl;
			std::cout<<std::endl;
		
			for (int i = 0 ; i < tam ; i++){
				if(mao[i]->get_valor() == COMPRA_4  ){	
					std::cout<< "  " << i << " ";
					mao[i]->print_carta();
				}	
			}
			std::cout <<std::endl;	

			std::cout<<"Escolha a posicao da carta +4(COMPRA_4) de sua mao para jogar :" << std::endl;
			std::cin >> pos;
			Carta *to_return = mao[pos];
		   
		    //caso o usuario erre na digitaçao
			while (to_return->get_valor() != COMPRA_4  ){
				std::cout<<"ERRO ERRO ERRO ERRO escolha uma carta +4:" << std::endl;
				std::cin >> pos;
				to_return = mao[pos];
			}
			
			mao[pos] = nullptr;
			mao.erase(mao.begin() + pos);
			return to_return;
	}
	
	
