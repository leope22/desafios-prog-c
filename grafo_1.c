/* Problema
O grau de um vértice v de um grafo é a quantidade de arestas que incide em v. Um grafo é regular
se todo vértice tem o mesmo grau. Faça um programa que verifique se um grafo representado na 
entrada é regular e, em caso afirmativo, qual o grau comum de todos os vértices. Seu programa
deve utilizar uma matriz para representar o grafo de entrada e conter a definição de duas funções:
uma que faz a leitura da entrada e constrói a matriz que representa o grafo, e outra que verifica
se o grafo é regular.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com dois inteiros
N e M (1 < N ≤ 300, 1 ≤ M ≤ 500), separados por espaços, que representam o número de vértices
e o número de arestas do grafo de entrada. As M linhas subsequentes contêm dois inteiros u e v
separados por espaços, que informam que existe uma aresta ligando u a v no grafo.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve ser uma linha que diz “O grafo
eh regular, de grau comum k.” em caso afirmativo (onde k representa o grau calculado) ou “O
grafo nao eh regular.” caso contrário. 
*/ 

#include <stdio.h>
#define MAXN 500

void leGrafo(int graph[MAXN][MAXN], int N, int M){
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            graph[i][j] = 0;
        }
    }
    
    int u, v;
    
    for(int i=0; i < M; i++){
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

int grafoRegular(int graph[MAXN][MAXN], int N){
    int somalinhas[N], soma;
    
    for(int i=0; i < N; i++){
        soma = 0;
        for(int j=0; j < N; j++){
            soma += graph[i][j];
        }
        somalinhas[i] = soma;
    }
    
    for(int i=0; i < N; i++){
        for(int j=i+1; j < N; j++){
            if(somalinhas[i] != somalinhas[j]){
                return 0;
            }else if((somalinhas[i] == somalinhas[j]) && (i == N - 2 && j == N - 1)){
                return somalinhas[i];
            }
        }
    }
}

int main(int argc, char** argv){
	
    int N, M;
    scanf("%d %d", &N, &M);
    int resultado, graph[MAXN][MAXN];
    leGrafo(graph, N, M);
    resultado = grafoRegular(graph, N);
    
    if (resultado == 0){
        printf("O grafo nao eh regular.\n");
    } else {
        printf("O grafo eh regular, de grau comum %d.\n", resultado);
    }
    
    return 0;
}