/* Problema
Escreva um programa em C que recebe da entrada padrão (terminal) n valores e calcula a média
aritmética, desvio padrão e média geométrica desses valores.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com um número
n (1 ≤ n ≤ 100,000) que representa a quantidade de valores utilizados para o cálculo da média
aritmética, desvio padrão e média geométrica, seguido de n valores inteiros xi
(1 ≤ xi ≤ 100,000) separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal) em três linhas no formato:
“A média aritmética é x”, onde x é o valor da média aritmética com duas casas decimais.
“O desvio padrão é y”, onde y é o valor do desvio padrão com duas casas decimais.
“A média geométrica é z”, onde z é o valor da média geométrica com duas casas decimais. */

#include <stdio.h>
#include <math.h>

int main() {
    long int n;
    double media, soma = 0, desvpad, variancia = 0, elemediageo = 1, mediageo;
    scanf("%ld", &n);
    double v[n];
    
    for (long int i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
        soma = soma + v[i];
    }
    
    media = soma / n;

    for (long int j = 0; j < n; j++) {
        variancia = variancia + ((v[j] - media) * (v[j] - media));
    }

    variancia = variancia / n;
    desvpad = sqrt(variancia);
  
    for (long int k = 0; k < n; k++) {
        elemediageo *= v[k];
    }
  
    mediageo = pow(elemediageo, (float)1/n);
  
    printf("A média aritmética é %.2lf\n", media);
    printf("O desvio padrão é %.2lf\n", desvpad);
    printf("A média geométrica é %.2lf\n", mediageo);

    return 0;
}