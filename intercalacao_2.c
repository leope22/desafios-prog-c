/* Problema
Escreva um programa em C que recebe da entrada padrão (terminal) dois conjuntos de valores em
ordem crescente, o primeiro com n valores e o segundo com m valores, e determine quais valores
pertencem a ambos os conjuntos. Cada conjunto, individualmente, não tem repetição de elementos.
Você deve fazer uma modificação no algoritmo de Intercalação visto em aula para maior
eficiência da solução.

Entrada
A entrada deve ser lida da entrada padrão (teclado) e contém duas linhas. A primeira linha com
n+1 números inteiros separados por espaços. O primeiro inteiro, n (1 ≤ n ≤ 10.000), é a quantidade
de elementos do primeiro conjunto, enquanto os ni números inteiros seguintes (-250.000 ≤ ni ≤
250.000) são os valores do conjunto (ordenados). A segunda linha contém m + 1 números inteiros
separados por espaços. O primeiro inteiro, m (1 ≤ m ≤ 10.000), é a quantidade de elementos do
segundo conjunto, enquanto os mi números inteiros seguintes (-250.000 ≤ mi ≤ 250.000) são os
valores do conjunto (ordenados).

Saída
A saída deve ser escrita na saída padrão (terminal) com todos os números que pertencem aos dois
conjuntos da entrada ordenados em ordem crescente. */

#include <stdio.h>

int main(){
	long int i, j, k, tamanho1, tamanho2, tamanho3;
	
    scanf("%ld", &tamanho1);
    long int numeros1[tamanho1];
    for (int l = 0; l < tamanho1; l++){
  	    scanf("%ld", &numeros1[l]);
    }
    scanf("%ld", &tamanho2);
    long int numeros2[tamanho2];
    for (int m = 0; m < tamanho2; m++){
  	    scanf("%ld", &numeros2[m]);
    }
    tamanho3 = tamanho1 + tamanho2;
    long int conjuntos[tamanho3];
    for(i = 0, j = 0, k = 0; i < tamanho3; i++){
        if(j < tamanho1 && k < tamanho2){
		    if(numeros1[j] < numeros2[k]){
                conjuntos[i] = numeros1[j]; 
                j++;
		    }
		    else if(numeros1[j] > numeros2[k]){
                conjuntos[i] = numeros2[k]; 
                k++;
	        }
	        else if(numeros1[j] == numeros2[k]){
		        conjuntos[i] = numeros1[j]; 
                j++;
                printf("%ld ", conjuntos[i]); 
                i++;
		        conjuntos[i] = numeros2[k]; 
                k++;
            }
		    if(j == tamanho1 || k == tamanho2){
		        break;
	        }
	    }
    }
    printf("\n");
    return 0;
}