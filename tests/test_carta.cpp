#include "doctest.h"
#include "carta.h"

#define ROXO 'm'
#define LOKO 'n'


	TEST_CASE("Testando Construtor da Carta"){		
		Carta a(RED, '0');
		CHECK(a.get_cor() == RED);
		CHECK(a.get_valor() == '0');
		
		Carta b(BLUE, PULAR);
		CHECK(b.get_cor() == BLUE);
		CHECK(b.get_valor() == PULAR);
		
		Carta c(GREEN, REVERTER);
		CHECK(c.get_cor() == GREEN);
		CHECK(c.get_valor() == REVERTER);

		Carta d(YELLOW, COMPRA_2);		
		CHECK(d.get_cor() == YELLOW);
		CHECK(d.get_valor() == COMPRA_2);	
		
		Carta e(ESPECIAL, CORINGA);		
		CHECK(e.get_cor() == ESPECIAL);
		CHECK(e.get_valor() == CORINGA);

		Carta f(ESPECIAL,COMPRA_4);		
		CHECK(f.get_cor() == ESPECIAL);
		CHECK(f.get_valor() == COMPRA_4);	
		
	}

	TEST_CASE("Testando Exceções do Construtor"){
		CHECK_THROWS(new Carta( ROXO, '0'));
        CHECK_THROWS(new Carta( RED, 't'));
        CHECK_THROWS(new Carta( RED, LOKO));
	}
	
	TEST_CASE("Testando função set_cor() e tira_cor_especial()"){
		
		Carta a(ESPECIAL, CORINGA);
		CHECK(a.get_cor() == ESPECIAL);
		
		a.set_cor(BLUE);
		CHECK(a.get_cor() == BLUE);
		
		a.tira_cor_especial();
		CHECK(a.get_cor() == ESPECIAL);

        CHECK_THROWS(a.set_cor( ROXO));
	}
	
	//COMO TESTAR PRINT DA CARTA?? R : Nao sei 
	
	TEST_CASE("Testando Funções set_jogador_alvo() e get_jogador_alvo()"){
		Carta a(RED, '0');
		CHECK(a.get_jogador_alvo() == -1);
		
		a.set_jogador_alvo(2);
		CHECK(a.get_jogador_alvo() == 2);
	}