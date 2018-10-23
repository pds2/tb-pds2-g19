 #include <iostream>
#include "carta.h"
#include "baralho.h"
#include "jogador.h"
#include "pilha.h"

int main(){

	Baralho baralho;
	Pilha pilha;
	baralho.embaralhar();

	
	Jogador matheus("matheus");
	for (int i = 0;i  < 7;i++){
		matheus.compra_carta(baralho);
	}
	std::cout<< "mao matheus 1" << std::endl;
	matheus.print_mao();
	
	for (int i = 0;i  < 7;i++)
		matheus.jogada(0,pilha);
	
	std::cout<< "mao matheus 2:" << std::endl;
	matheus.print_mao();
	std::cout<< "pilha :" << std::endl;
	pilha.print_pilha();

	return 0;
}
