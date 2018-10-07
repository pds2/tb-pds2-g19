#include "vetor.h"

#ifndef MATRIZ_H
#define MATRIZ_H

#define t 't'
using namespace std;


class Matriz {

		private :
				
			int linhas;
			int colunas;
			Vetor *m ;


		public:

			// CONTRUTORES 			
				Matriz();
				Matriz(int  l,int c );
				Matriz(Vetor array[],int l,int c);
				Matriz (Vetor matriz_linha);
				Matriz (Vetor array[], int l);
				
				
			//METODOS
				int get_linhas() const;
				int get_colunas() const;
				void print_matriz() const;
				Matriz cofator(int l,int c);
				float Determinante();
			//OPERADORES
				Vetor& operator[](int i);
				Matriz operator[](Vetor add);
				Matriz operator*(Matriz B);
				Matriz operator*(float alfa);
				friend Matriz operator*(float alfa,Matriz b);
				Matriz operator^(int alfa);
				Matriz operator^(char transposta);
	};

	

#endif