#include "doctest.h"
#include "carta.h"
#include "baralho.h"

#define TOTAL_CARTAS 108

    TEST_CASE("Testando Construtor"){
        Baralho a;

        CHECK(a.get_tamanho() == TOTAL_CARTAS);
    }

    TEST_CASE("Testando Funções remove_fim, adiciona_carta e get_ultima_carta"){
        Baralho a;
        CHECK(a.get_tamanho() == TOTAL_CARTAS);

        a.remove_fim();
        CHECK(a.get_tamanho() == TOTAL_CARTAS-1);

        Carta *b = new Carta(RED, '0');

        a.adiciona_carta(b);
        CHECK(a.get_tamanho() == TOTAL_CARTAS);

        CHECK(a.get_ultima_carta() == b);
    }