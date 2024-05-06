/* Problema
Dadas duas matrizes A e B de dimensões n × n, determinar se B é a inversa multiplicativa de A,
isto é, se AB = I, onde I denota a matriz identidade (com todas as células nulas exceto na diagonal
principal, onde todas as células têm valor 1).

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com um inteiro
N (1 ≤ N ≤ 200) que representa a dimensão das matrizes. As 2N linhas subsequentes contêm N
números inteiros aij tais que -1000 ≤ aij ≤ 1000, sendo que as primeiras N linhas correspondem
à matriz A e as N linhas seguintes à matriz B.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve ser dada por uma linha com a
resposta “Sim” ou “Não”, dependendo se B é a inversa multiplicativa de A ou não. */

#include <stdio.h>

int main(){
	long long int tam;
	
	scanf("%lld", &tam);
	
	long long int matriz1[tam][tam];
	long long int matriz2[tam][tam];
	long long int matriz3[tam][tam];
	
	for(long long int i = 0; i < tam; i++){
		for(long long int j = 0; j < tam; j++){ 
			matriz3[i][j] = 0;
		}
    }
				         
	for(long long int i = 0; i < tam; i++){
		for(long long int j = 0; j < tam; j++){ 
			scanf("%lld", &matriz1[i][j]);
		}
    }
    
    for(long long int i = 0; i < tam; i++){
		for(long long int j = 0; j < tam; j++){ 
			scanf("%lld", &matriz2[i][j]);
		}
    }
    
    for(long long int i = 0; i < tam; i++){
		for(long long int j = 0; j < tam; j++){
			for(long long int k = 0; k < tam; k++){				
			    matriz3[i][j] += (matriz1[i][k] * matriz2[k][j]);
		    }
		    if((i != j) && (matriz3[i][j] != 0)){
				printf("Nao\n");
				return 0;
			}else if((i == j) && (matriz3[i][j] != 1)){
				printf("Nao\n");
				return 0;
            }else if((i == tam - 1) && (j == tam - 1) && (matriz3[i][j] == 1)){
				printf("Sim\n");
			}
		}
	}
    return 0;
}