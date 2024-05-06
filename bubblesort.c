/* Problema
Escreva um programa em C que recebe da entrada padrão (terminal) n valores e retorna os mesmos
valores em ordem crescente. Pode haver repetição dos valores, e essa repetição deve aparecer na
saída também. Seu programa deve implementar o algoritmo BubbleSort para efetuar a ordenação.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com n + 1
números inteiros separados por espaços. O primeiro número é n, (1 ≤ n ≤ 10,000), e é a quantidade
de elementos a ordenar, enquanto os ni números inteiros seguintes (−250,000 ≤ ni ≤ 250,000) são
os valores a ordenar.

Saída
A saída deve ser escrita na saída padrão (terminal) com todos os n números da entrada ordenados
em ordem crescente. */

#include <stdio.h>

int main() {
    long int tamanho, aux;
    scanf("%ld", &tamanho);
    long int numeros[tamanho];
    for (int l = 0; l < tamanho; l++) {
        scanf("%ld", &numeros[l]);
    }
    for (int contador = 1; contador < tamanho; contador++) {
        for (int i = 0; i < tamanho - 1; i++) {
            if (numeros[i] > numeros[i + 1]) {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
            }
        }
    }
    for (int k = 0; k < tamanho; k++) {
        printf("%ld ", numeros[k]);
    }
    printf("\n");
    return 0;
}