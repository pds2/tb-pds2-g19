#include <iostream>
#include "carta.h"
#include "baralho.h"
#include "jogador.h"
#include "pilha.h"

int main(){

	Baralho jogo;
	jogo.embaralhar();
	Jogador matheus("matheus");
	matheus.compra_carta(jogo);
	jogo.print_baralho();
	std::cout<< "mao matheus " << std::endl;
	matheus.print_mao();
	
	return 0;
}
