#include excecoes.cpp

  	const char* CartaInvalidaException::what() const noexcept{
          return "Carta Inválida"
    }

  	const char* BaralhoInvalidoException::what() const noexcept{
          return "Baralho Inválido"
    }

  	const char* JogadorInvalidoException::what() const noexcept{
          return "Jogador Inválido"
    }

  	const char* BotInvalidoException::what() const noexcept{
          return "Bot Inválido"
    }

  	const char* JogoInvalidoException::what() const noexcept{
          return "Jogo Inválido"
    }