/* Considere uma matriz A de 3 linhas e n ≥ 1 colunas cujas células são valores
inteiros. Desejamos encontrar uma sequência S = (s1, s2, . . . , sn) de n elementos tal
que todo sj é um elemento da coluna j de A, para j = 1, 2, . . . , n.

Além disso, para todo j = 2, . . . , n, se sj = Aij , então necessariamente sj−1 = Atj−1 
onde |t − i| ≤ 1. Em outras palavras, o elemento anterior da sequência deve sempre vir da mesma
linha ou de uma linha adjacente. Note que apenas quando utilizamos um elemento da linha 2 há 3
possibilidades de escolha para o anterior; caso contrário, são apenas duas possibilidades.

Dentre todas as sequências possíveis que satisfazem essas restrições, queremos encontrar uma
cuja soma dos elementos é a maior possível e finalmente qual o valor desta soma.
Por exemplo, para a matriz abaixo
-15 8 15 -2 9 8
3 -10 4 -3 7 -1
10 7 2 5 6 11
uma sequência de soma máxima é a seguinte (10, 7, 4, 5, 7, 11) = 44.
Projete um algoritmo para resolver este problema. Sugestão: pense indutivamente.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém quatro linhas. A primeira
linha com um inteiro N correspondente ao número de colunas da matriz sendo que 1 ≤ N ≤ 100. As 3
linhas seguintes contêm uma sequência de N elementos M onde −500 ≤ M ≤ 500. Cada elemento M
corresponde ao valor do inteiro localizado na coordenada correspondente na matriz.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve ser apenas o número
correspondente a soma máxima e uma quebra de linha. */

// Somar incrementando os elementos da matriz com o elemento da coluna anterior seguindo as restrições e comparar para ver qual foi o maior.

#include <stdio.h>

int maior(int X, int Y) {
    return (X > Y) ? X : Y;
}

int main() {
    long int colunas;
    scanf("%ld", &colunas);
    
    const int MAX_COLUNAS = 100;
    int matriz[3][MAX_COLUNAS];
    
    for (long int i = 0; i < 3; i++) {
        for (long int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for (long int j = 1; j < colunas; j++) {
        matriz[0][j] += maior(matriz[0][j - 1], matriz[1][j - 1]);
        matriz[1][j] += maior(matriz[1][j - 1], maior(matriz[0][j - 1], matriz[2][j - 1]));
        matriz[2][j] += maior(matriz[2][j - 1], matriz[1][j - 1]);
    }
    
    long int soma = maior(matriz[0][colunas - 1], maior(matriz[1][colunas - 1], matriz[2][colunas - 1]));
    
    printf("%ld\n", soma);
    
    return 0;
}