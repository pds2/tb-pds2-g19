#include <iostream>
#include <string>

#ifndef VETOR_H
#define VETOR_H

using namespace std;

class Vetor {

		private:

			int tamanho; 
			float *v;

		public:

			//CONSTRUTORES 			
				Vetor();
				Vetor (string num);
				Vetor (float vec[],int t);
				Vetor (float unitario);
				Vetor (int unitario);
				~Vetor(){delete v;}
			
			//METODOS					
				void set_tamanho(int tam);
				int get_tamanho() const;
				float *get_vetor_float() const;
				void print_vetor() const;

			//OPERADORES 
				float& operator[](int j);
				void operator+= (Vetor add);
				void operator+= (float add);
				Vetor operator,(float add) const;
				//friend Vetor operator,(int a,int b);
				Vetor operator,(int add_i) const;
				Vetor operator+(Vetor b) const;
				void operator()(int set_tam);
				Vetor operator= (int add);


	};


#endif

	