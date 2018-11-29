#include "doctest.h"
#include "jogador.h"
#include "baralho.h"
#include "carta.h"

#define MAO_INICIAL 7

    TEST_CASE("Testando Construtor do Jogador"){
        Jogador a("Joao");

        CHECK(a.get_nome() == "Joao");
    }

    TEST_CASE("Testando a Função set_nome"){
        Jogador a("Joao");
        CHECK(a.get_nome() == "Joao");

        a.set_nome("Maria");
        CHECK(a.get_nome() == "Maria");
    }

    TEST_CASE("Testando as Funções compra_carta num_cartas"){
        Baralho a;
        Jogador b("Joao");

        b.compra_carta(a, MAO_INICIAL);
        CHECK(b.num_cartas() == MAO_INICIAL);
    }

    TEST_CASE("Testando a Função cartas_jogaveis"){
        Baralho a;
        Jogador b("Joao");
        Carta *c = new Carta(RED, '0');

        b.compra_carta(*a, MAO_INICIAL);
  
        CHECK(b.cartas_jogaveis(c) == MAO_INICIAL);
    }