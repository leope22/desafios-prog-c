/* Problema
O grau de um vértice v de um grafo é a quantidade de arestas que incide em v. Um grafo é regular
se todo vértice tem o mesmo grau. Um grafo possui triângulo se existem 3 vértices u, v e w tais 
que existem as arestas uv, uw e vw. Um grafo possui quadrilátero se existem 4 vértices u, v, w e 
z tais que existem as arestas uv, uz, vw e wz. Faça um programa que verifique se um grafo representado 
na entrada é regular e quantos triângulos e quadriláteros ele possui. Seu programa deve utilizar uma 
matriz para representar o grafo de entrada e conter a definição de quatro funções: uma que faz a 
leitura da entrada e constrói a matriz que representa o grafo, uma que verifica se o grafo é regular, 
uma que conta a quantidade de triângulos e uma que conta a quantidade de quadriláteros.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com dois inteiros
N e M (1 < N ≤ 300, 1 ≤ M ≤ 500), separados por espaços, que representam o número de vértices
e o número de arestas do grafo de entrada. As M linhas subsequentes contêm dois inteiros u e v
separados por espaços, que informam que existe uma aresta ligando u a v no grafo.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve ser uma linha que diz “O grafo
eh regular, de grau comum k.” em caso afirmativo (onde k representa o grau calculado) ou “O
grafo nao eh regular.” caso contrário. */

#include <stdio.h>

#define MAXN 500

void leGrafo(long long int graph[MAXN][MAXN], long long int N, long long int M) {
    for(long long int i = 0; i < N; i++) {
        for(long long int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }
    
    long long int u, v;
    
    for(long long int i = 0; i < M; i++) {
        scanf("%lld %lld", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

long long int grafoRegular(long long int graph[MAXN][MAXN], long long int N) {
    long long int somalinhas[MAXN], soma;
    
    for(long long int i = 0; i < N; i++) {
        soma = 0;
        for(long long int j = 0; j < N; j++) {
            soma += graph[i][j];
        }
        somalinhas[i] = soma;
    }
    
    for(long long int i = 0; i < N; i++) {
        for(long long int j = i + 1; j < N; j++) {
            if(somalinhas[i] != somalinhas[j]) {
                return 0;
            } else if((somalinhas[i] == somalinhas[j]) && (i == N - 2 && j == N - 1)) {
                return somalinhas[i];
            }
        }
    }
}

long long int contaTriangulos(long long int graph[MAXN][MAXN], long long int N) {
    long long int triangulos = 0;
    long long int auxLinha;
    long long int auxColuna; 
    for(long long int i = 0; i < N; i++) {
        for(long long int j = 0; j < N; j++) {
            if(graph[i][j] == 1) {
                auxLinha = i;
                auxColuna = j;
                for(long long int k = 0; k < N; k++) {
                    if(graph[auxLinha][k] == 1 && graph[auxColuna][k] == 1) {
                        triangulos++;
                    }
                }
            }
        }
    }
    return (triangulos / 6);
}

long long int contaQuadrilateros(long long int graph[MAXN][MAXN], long long int N) {
    long long int quadrilateros = 0;
    long long int auxLinha;
    long long int auxColuna; 
    for(long long int i = 0; i < N; i++) {
        for(long long int j = 0; j < N; j++) {
            if(graph[i][j] == 1) {
                auxLinha = i;
                auxColuna = j;
                for(long long int k = 0; k < N; k++) {
                    for(long long int l = 0; l < N; l++) {
                        if(k != l && i != j && k != i && l != j && 
                           graph[auxLinha][l] == 1 && graph[auxColuna][k] == 1 && 
                           graph[l][k] == 1) {
                            quadrilateros++;
                        }
                    }
                }
            }
        }
    }
    return (quadrilateros / 4);
}

int main(int argc, char** argv) {
    long long int N, M;
    scanf("%lld %lld", &N, &M);
    long long int resultado, graph[MAXN][MAXN];
    leGrafo(graph, N, M);
    resultado = grafoRegular(graph, N);
    if (resultado == 0) {
        printf("O grafo nao eh regular. Possui %lld triangulos e %lld quadrilateros.\n", contaTriangulos(graph, N), contaQuadrilateros(graph, N));
    } else {
        printf("O grafo eh regular, de grau comum %lld. Possui %lld triangulos e %lld quadrilateros.\n", resultado, contaTriangulos(graph, N), contaQuadrilateros(graph, N));
    }
    return 0;
}