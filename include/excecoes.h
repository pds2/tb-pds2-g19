#include <stdexcept>

#ifndef UNO_EXCECOES_H
#define UNO_EXCECOES_H

	class CartaInvalidaException : public std::exception {
		public:
	  		virtual const char* what() const noexcept override;
	};
	class BaralhoInvalidoException : public std::exception {
		public:
	  		virtual const char* what() const noexcept override;
	};
	class JogadorInvalidoException : public std::exception {
		public:
	  		virtual const char* what() const noexcept override;
	};
	class BotInvalidoException : public std::exception {
		public:
	  		virtual const char* what() const noexcept override;
	};
	class JogoInvalidoException : public std::exception {
		public:
	  		virtual const char* what() const noexcept override;
	};

#endif