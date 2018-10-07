#include "matriz.h"
#include "vetor.h"


using namespace std;

	//CONSTRUTORES	
			Matriz::Matriz (){
				linhas = 0;
				colunas = 0;
				m =  nullptr;
			}
			Matriz::Matriz(int  l ,int c ){
					linhas = l;
					colunas = c;
					m  = new Vetor[linhas];
					for(int i = 0; i  < linhas ;i++){
						m[i].set_tamanho(colunas);
					}
					for (int i = 0;i < l;i++)
						for(int j = 0;j < c ;j++)
							m[i][j] = 0;
				}
			Matriz::Matriz(Vetor array[],int l,int c){
				m =  array;
				linhas = l;
				colunas = c;
			}
			Matriz::Matriz (Vetor matriz_linha){
				linhas = 1;
				colunas = matriz_linha.get_tamanho();
				m = new Vetor;
				m[0] = matriz_linha;
			}
			Matriz::Matriz (Vetor array[], int l){
				linhas = l;
				colunas = array[0].get_tamanho();
				m =array;
			}


	//METODOS
			int Matriz::get_linhas() const{
				return linhas;
			}
			int Matriz::get_colunas() const{
				return colunas;
			}
			void Matriz::print_matriz() const{
				for (int i =0 ;i < linhas;i++)
					m[i].print_vetor();
					cout<<"\n";
			}
			Matriz Matriz::cofator(int l,int c){
				Matriz  cofator(linhas - 1,colunas -1);
				int i_mm = 0 ,j_mm = 0;	
				for (int i = 0 ; i  < linhas;i++){						
					if (i == l)
							i_mm = 1;
					j_mm = 0;	 
					
					for (int j = 0 ; j < colunas ;j++){
						if (j == c) 
							j_mm = 1;
						if (i != l && j != c){
							//cout << "cofator[" << i - i_mm <<"][" << j - j_mm <<"] == m["<< i <<"][" << j << "]" <<endl;
							cofator[i - i_mm][j - j_mm] = m[i][j];
						}
					}
				}
				return cofator;
			}
			float Matriz::Determinante(){
				if (linhas != colunas)
					return -12345678;
				
				if (linhas < 0 || colunas < 0)
					return -12345678;
				
				if (linhas == 1 && colunas == 1)
					return m[0][0];
				
				if (linhas == 2  && colunas == 2)
					return (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
				
				float det = 0;

				// if (linhas == 3  && colunas == 3)
				// 	return (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
				
				for (int i = 0; i < colunas; i++){
					if (i % 2 == 0){
						//cout << "antes "<< det <<endl;
						det = det + m[0][i]*cofator(0,i).Determinante();
						//cout << "depois " << det <<endl;
					}
						
					else { 
						//cout << "antes "<< det <<endl;
						det =det - m[0][i]*cofator(0,i).Determinante();
						//cout << "depois " << det <<endl;
					}
				  
				}

				return det;	
			}
	//OPERADORES	 	

			Vetor& Matriz::operator[](int i ){	
				 if( i >= 0 &&  i< linhas )
				 	return m[i];
			}
			Matriz Matriz::operator[](Vetor add){
		  		const int l = linhas;
		  		if (colunas == 0)
		        	colunas = add.get_tamanho();
		  		const int c = colunas;
		       
		        Vetor *copia = new Vetor[l + 1];
		       
		        for (int i = 0;i < l ;i++)
		            copia[i] = m[i];

		        copia[l] = add;

		        return Matriz(copia,l + 1,c);
			}
			Matriz Matriz::operator*(Matriz b){
				
				int b_colunas = b.get_colunas();	
				int b_linhas = b.get_linhas();
				Matriz matriz(linhas,b_colunas);
				
				if (colunas == b_linhas)
					for (int i = 0; i < linhas ;i++)
						for (int j = 0;j < b_colunas; j++)
							for (int k = 0 ;k < colunas;k++)
								matriz[i][j] += m[i][k]*b[k][j];
							
					return matriz;
			}
			Matriz Matriz::operator*(float alfa){
				Matriz matriz(linhas,colunas);
				for (int i = 0;i < linhas;i++)
					for(int j = 0;j < colunas;j++)
						matriz[i][j] = m[i][j]*alfa;

				return matriz;
			}
			Matriz operator*(float alfa , Matriz b){
				Matriz matriz(b.linhas,b.colunas);
				for (int i = 0;i < b.linhas;i++)
					for(int j = 0;j < b.colunas;j++)
						matriz[i][j] = b.m[i][j] *alfa;

				return matriz;
			}
			Matriz Matriz::operator^(int alfa){
				const Matriz &a = *this;
				Matriz to_return = a;     
				if (alfa > 0)
					for (int i = 0; i < alfa - 1; i++)
						to_return = to_return * a;

					return to_return;
			}
			Matriz Matriz::operator^(char tr){
				Matriz &a = *this;
				Matriz transposta(colunas,linhas);
				for (int i = 0;i < linhas ;i++)
					for (int j = 0;j < colunas;j++)
						transposta[j][i] = a[i][j];


				return transposta;
			}
