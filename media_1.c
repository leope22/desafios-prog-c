/* Problema
Escreva um programa em C que receba da entrada padrão (terminal) n valores e calcule a média
simples destes valores. Ou seja, se os valores passados na entrada são x1, x2, ..., xn, então
você deve calcular a média aritmética destes valores, que é dada por (x1 + x2 + ... + xn) / n.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com um número
n (1 ≤ n ≤ 100,000) que representa a quantidade de valores utilizados para o cálculo da média,
seguido de n valores inteiros xi (1 ≤ xi ≤ 100,000) separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal) em uma linha no formato: “A média aritmética
é x”, onde x é o valor calculado, representado com duas casas decimais. */

#include <stdio.h>
int main()
{
    long int i, n;
    double a, b=0, c=0;
    scanf("%ld", &n);
    double d1[n];
    for (i = 0; i < n; i++){
        scanf("%lf", &d1[i]);
        c = c + d1[i];
    }
    a = c / n;
    printf("A media aritmetica eh %0.2lf.\n", a);
    return 0;
}