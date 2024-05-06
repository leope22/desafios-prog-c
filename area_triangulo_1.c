/* Problema
Escreva um programa em C que receba da entrada padrão (terminal) as coordenadas
Px, Py, Qx, Qy, Rx, Ry de três pontos P, Q e R no plano cartesiano e encontre a
área do triângulo com vértices nos pontos P, Q e R. Caso os pontos P, Q e R
sejam colineares, não existe triângulo e a resposta deve indicar tal fato.

Entrada
A entrada deve ser lida da entrada padrão (teclado). Ela consiste em uma linha
com seis números de ponto flutuante Px, Py, Qx, Qy, Rx, Ry (-10^6 ≤ Px, Py, Qx,
Qy, Rx, Ry ≤ 10^6), separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal) em uma linha. O formato da
linha depende dos pontos da entrada serem colineares ou não. Caso os pontos não
sejam colineares, a saída deve estar no seguinte formato: "A área do triângulo
é x.", onde x representa a área calculada com 3 casas decimais de precisão.
Caso os pontos sejam colineares, a saída deve estar no seguinte formato: "Não
há triângulo pois os pontos são colineares." */

#include <stdio.h>

int main() {
    double Px, Py, Qx, Qy, Rx, Ry;
    scanf("%lf %lf %lf %lf %lf %lf", &Px, &Py, &Qx, &Qy, &Rx, &Ry);
    double D = ((Px * Qy) + (Py * Rx) + (Qx * Ry)) - ((Qy * Rx) + (Px * Ry) + (Py * Qx));
    if (D == 0) {
        printf("Não há triângulo pois os pontos são colineares.\n");
    } else {
        if (D < 0) {
            printf("A área do triângulo é %.3lf.\n", (D / 2) * (-1));
        } else {
            printf("A área do triângulo é %.3lf.\n", D / 2);
        }
    }
    return 0;
}