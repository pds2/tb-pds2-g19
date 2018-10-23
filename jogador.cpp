#include "jogador.h"
#include "carta.h"
#include "pilha.h"
#include "baralho.h"

	Jogador::Jogador(){}
	Jogador::Jogador(std::string name){
		nome = name;
	}
	Jogador::~Jogador(){
		for(int i = 0;i < mao.size() ;i++){
			delete mao[mao.size() - 1];
			mao.pop_back();
		}
	}
	//METODOS
	std::string Jogador::get_nome() const{
		return nome;
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

	void Jogador::jogada (int pos,Pilha &pilha){
		pilha.inserir_fim(mao[pos]);
		mao[pos] = nullptr;
		mao.erase(mao.begin() + pos);
	}
	
	void Jogador::print_mao() const	{
		int tam = this->num_cartas();
		for (int i = 0 ; i < tam ; i++)
			mao[i]->print_carta();
	}
