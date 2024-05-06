/* Problema
Escreva um programa em C que leia dois números inteiros a₀ e n da entrada padrão
(terminal) e calcule o resultado da soma s de uma PA de razão 1 com termo inicial
a₀ e n parcelas.

Entrada
A entrada deve ser lida da entrada padrão (teclado). Ela consiste em uma linha com
dois inteiros a₀ e n (1 ≤ a₀, n ≤ 10^6), separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal) em uma linha no seguinte formato:
"O resultado da soma dos termos da PA de razão 1, com início a₀ e n termos é s.".
Certifique-se de que haja uma quebra de linha ao final da frase. */

#include <stdio.h>

int main() {
    long long int a0, n, s;
    scanf("%lld %lld", &a0, &n);
    s = (a0 * n) + ((n - 1) * n) / 2;
    printf("O resultado da soma dos termos da PA de razao 1, com inicio %lld e %lld termos eh %lld.\n", a0, n, s);
    return 0;
}