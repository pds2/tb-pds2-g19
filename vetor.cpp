#include <string>
#include <iostream>
#include "vetor.h"

using namespace std;


	//CONSTRUTORES
			
			Vetor::Vetor(){v = nullptr; tamanho = 0;}
			
			Vetor::Vetor(string num){
				tamanho = 1;
				v = new float;
				v[0] = stof(num);
			}
			
			Vetor::Vetor (float vec[],int t){
				tamanho = t;
				v = vec;
			}
			
			Vetor::Vetor (float unitario){
				tamanho = 1;
				v = new float;
				v[0] = unitario;
			}
			
			Vetor::Vetor (int unitario){
				
				tamanho = 1;
				v = new float;
				v[0] =(float) unitario;
			}

    //METODOS

			void Vetor::set_tamanho(int tam){
				int tam_velho = tamanho;
				float *novo = new float[tam];
				for (int i = 0;i < tamanho ;i++)
					novo[i] = v[i];
				tamanho = tam;
				float *to_delete = v;
				v = novo;
				delete to_delete;
				//caso o tamanho seja maior do vetor coloca zero nessas posicoes
				for (int i = tam_velho;i < tam;i++){
					v[i] = 0 ;
				}
			}
			
			int Vetor::get_tamanho() const{
				return tamanho;
			}
			
			float *Vetor::get_vetor_float() const{
				return v;
			}
			void Vetor::print_vetor() const{
				cout<<"[";
				for(int i = 0; i < tamanho; i++){
					cout << v[i];
					if (i != tamanho - 1)
						cout <<",";
				}
				cout << "]\n";
			}
	//OPERADORES 

			float& Vetor::operator[](int j){
				static float lixo = -1234567;
				if (j >=0 && j < tamanho )
					return v[j];
				else 
					return lixo;

			}
			
			void Vetor::operator+= (Vetor add){
				int tam_adicionado = add.get_tamanho();
				
				float copia[tamanho + tam_adicionado];
				float *novo = new float[tamanho];
				for (int i = 0;i < tamanho ;i++)
					copia[i] = v[i];
				

				for (int i = 0; i < tam_adicionado; ++i)
					copia[i + tamanho] = add.get_vetor_float()[i];
			
				delete v;
				v = new float[tamanho];

				for (int i = 0;i < tamanho + tam_adicionado ;i++)
					v[i] = copia[i];


				tamanho +=tam_adicionado; 
				//apontando para o vetor que esta presente no objeto
				//tal vetor sera deletado 

				//return Vetor(tamanho,v);

			}
			void Vetor::operator+= (float add){

				const int  tam = tamanho;
		       
		        float *copia = new float[tam + 1];
		       
		        for (int i = 0;i < tam ;i++)
		            copia[i] = v[i];

		        copia[tam] = add;

		        float *to_delete = v;
		        v = copia;
		        delete to_delete;
		     
			}
			Vetor Vetor::operator,(float add) const{
		       
		        const int  tam = tamanho;
		       
		        float *copia = new float[tam + 1];
		       
		        for (int i = 0;i < tam ;i++)
		            copia[i] = v[i];

		        copia[tam] = add;

		        return Vetor(copia,tam + 1);
		    } 
		    // Vetor operator,(int a,int b){
		    		
		    // 	float f_a = (float)a;
		    // 	float f_b = (float)b;
		    // 	float *ptr = new float[2];
		    // 	ptr[0] = f_a;
		    // 	ptr[1] = f_b;

		    // 	return Vetor(ptr,2);

		    // }
		    Vetor Vetor::operator,(int add_i) const{

		    	float add = (float) add_i;
		    	const int  tam = tamanho;
		       
		        float *copia = new float[tam + 1];
		       
		        for (int i = 0;i < tam ;i++)
		            copia[i] = v[i];

		        copia[tam] = add;

		        return Vetor(copia,tam + 1);


		    }
		    
		    Vetor Vetor::operator+(Vetor b) const{
		    	const int  tam_a = tamanho;
		    	const int tam_b = b.get_tamanho();
		    	

		    	if (tam_a == tam_b){
		    		float *soma  = new float [tam_a];
		    		float *vetor_b = b.get_vetor_float();
		    		for (int i = 0; i < tam_a;i++){
		    			soma[i] = v[i] + vetor_b[i]; 
		    		}
		    		return Vetor(soma,tam_a);
		    	}
		    	else {
		    		cout << "ERRO SOMA DE VETORES DE TAMANHOS DIFERENTES" << endl;
		    		return Vetor(v,tamanho);
		    	}

		    }
		     Vetor Vetor::operator+(Vetor b) const{
		    	const int  tam_a = tamanho;
		    	const int tam_b = b.get_tamanho();
		    	

		    	if (tam_a == tam_b){
		    		float *soma  = new float [tam_a];
		    		float *vetor_b = b.get_vetor_float();
		    		for (int i = 0; i < tam_a;i++){
		    			soma[i] = v[i] + vetor_b[i]; 
		    		}
		    		return Vetor(soma,tam_a);
		    	}
		    	else {
		    		cout << "ERRO SOMA DE VETORES DE TAMANHOS DIFERENTES" << endl;
		    		return Vetor(v,tamanho);
		    	}

		    }
			
			void Vetor::operator()(int set_tam){
					set_tamanho(set_tam);
			}	
			Vetor Vetor::operator= (int add){
				return Vetor(add);
			}







	//Vetor::Vetor(int t = 0){
	//	tamanho = t;
	//	if (t != 0 ){
	//		v = new float[t];
	//		for(int i = 0; i < t;i++)
	//		v[i] = 0;
	//	} 	
	//	else
	//		v = nullptr;
	//}
	