/* Problema
Escreva um programa em C que recebe da entrada padrão (terminal) as coordenadas
Px, Py, Qx, Qy de dois pontos P e Q no plano cartesiano e encontra a área do triângulo
com vértices nos pontos P, Q e um terceiro ponto R na interseção entre a reta horizontal
que passa por P e a reta vertical que passa por Q. Caso os pontos P e Q se encontrem na
mesma linha horizontal ou vertical, o ponto R fica indefinido. Neste caso, a resposta
deve especificar que não existe triângulo e apenas dar o comprimento do segmento de reta
entre P e Q. Caso os pontos P e Q sejam idênticos, novamente o ponto P fica indefinido.
Neste caso, a resposta deve indicar que não existe triângulo, apenas um ponto.

Entrada
A entrada deve ser lida da entrada padrão (teclado). Ela consiste em uma linha com quatro
números de ponto flutuante Px, Py, Qx, Qy (-10^6 ≤ Px, Py, Qx, Qy ≤ 10^6), separados por
espaços.

Saída
A saída deve ser escrita na saída padrão (terminal) em uma linha. O formato da linha
depende de R estar definido ou não, e de haver um segmento de reta não trivial entre
P e Q, ou não. Caso o ponto R esteja definido, a saída deve estar no seguinte formato:
"A área do triângulo é x.", onde x representa a área calculada com 3 casas decimais de
precisão. Caso o ponto R seja indefinido, mas exista segmento de reta não trivial entre
P e Q, a saída deve estar no seguinte formato: "Não existe triângulo, apenas um segmento
de reta de comprimento x.", onde x representa o comprimento do segmento de reta com 3
casas decimais de precisão. Finalmente, caso o ponto R seja indefinido e o segmento de
reta entre P e Q seja trivial, a saída deve estar no seguinte formato: "Não existe
triângulo, apenas um ponto.". */

#include <stdio.h>

int main() {
    double Px, Py, Qx, Qy;
    scanf("%lf %lf %lf %lf", &Px, &Py, &Qx, &Qy);
    double Rx = Px;
    double Ry = Qy;
    double A = (Qx - Px);
    double B = (Qy - Py);
    double C = (A * B) / 2;
    double D = (Py - Qy) + (Px - Qx);
    if ((Qx == Px) && (Qy == Py)) {	
        printf("Não existe triângulo, apenas um ponto.\n");
    } else if ((Qx == Px) || (Qy == Py)) {
        if (D < 0) {
            printf("Não existe triângulo, apenas um segmento de reta de comprimento %.3lf.\n", D * (-1));
        } else {
            printf("Não existe triângulo, apenas um segmento de reta de comprimento %.3lf.\n", D);
        }
    } else if ((Qx != Px) || (Qy != Py)) {
        if (C < 0) {
            printf("A área do triângulo é %.3lf.\n", C * (-1));
        } else {
            printf("A área do triângulo é %.3lf.\n", C);
        }
    }
    return 0;
}