/* Problema
Escreva um programa em C que leia três números inteiros a₀, n e q da entrada padrão
(terminal) e calcule o resultado da soma s de uma PA de razão q com termo inicial a₀
e n parcelas.

Entrada
A entrada deve ser lida da entrada padrão (teclado). Ela consiste em uma linha com três
inteiros a₀, n e q (1 ≤ a₀, n, q ≤ 10^6), separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal) em uma linha no seguinte formato:
"O resultado da soma dos termos da PA de razão q, com início a₀ e n termos é s.".
Certifique-se de que haja uma quebra de linha ao final da frase. */

#include <stdio.h>

int main() {
    long long int a0, n, q, s;
    scanf("%lld %lld %lld", &a0, &n, &q);
    s = (a0 + (a0 + (n - 1) * q)) * n / 2;
    printf("O resultado da soma dos termos da PA de razao %lld, com inicio %lld e %lld termos eh %lld.\n", q, a0, n, s);
    return 0;
}