/* Problema
Escreva um programa em C que calcula o valor de um polinômio de grau n, ou seja,
anx^n + an-1x^(n-1) + ... + a2x^2 + a1x + a0. Seu programa deve receber da entrada
padrão (terminal) os valores de n e x seguidos dos n + 1 coeficientes ai, para
0 ≤ i ≤ n; e deve retornar o valor do polinômio calculado para o valor de x dado
na entrada.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém duas linhas.
A primeira contém dois inteiros, n e x, com 1 ≤ n ≤ 60 e 1 ≤ x ≤ 100, separados por
um espaço. A segunda linha contém todos os n + 1 coeficientes ai do polinômio, com
-123456789 ≤ ai ≤ 123456789.

Saída
A saída deve ser escrita na saída padrão (terminal) em uma linha, a qual deve conter
apenas o valor do polinômio calculado. */

#include <stdio.h>

int main() {
    long long int n, contador1 = 0, contador2 = 0, x = 0, a, res = 0, var = 1;
    scanf("%lld %lld", &n, &x);
    while (contador1 <= n) {
        scanf("%lld", &a);
        while (contador2 < contador1) {
            var = var * x;
            contador2 = contador2 + 1;
        }
        res = (a * var) + res;
        contador1 = contador1 + 1;
    }
    printf("%lld\n", res);
    return 0;
}