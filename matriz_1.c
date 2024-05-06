/* Problema
Dadas duas matrizes A e B de dimensões n × n, determinar se B é a inversa aditiva de A, isto é,
se A + B = 0, onde 0 denota a matriz nula (com todas as células nulas).

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com um inteiro
N (1 ≤ N ≤ 200) que representa a dimensão das matrizes. As 2N linhas subsequentes contêm N
números inteiros aij tais que -1000 ≤ aij ≤ 1000, sendo que as primeiras N linhas correspondem
à matriz A e as N linhas seguintes à matriz B.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve ser dada por uma linha com a
resposta “Sim” ou “Não”, dependendo se B é a inversa aditiva de A ou não. */

#include <stdio.h>

int main(){
    int tam;
    scanf("%d", &tam);
    int matriz1[tam][tam];
    int matriz2[tam][tam];
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){ 
            scanf("%d", &matriz1[i][j]);
        }
    }
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){ 
            scanf("%d", &matriz2[i][j]);
        }
    }
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){ 
            if(matriz1[i][j] + matriz2[i][j] != 0){
                printf("Nao\n");
                return 0;
            }else if((i == tam - 1) && (j == tam - 1) && (matriz1[i][j] + matriz2[i][j] == 0)){
                printf("Sim\n");
            }
        }
    }
    return 0;
}