/* Problema
Uma máquina de compras automática, como as que vendem bebidas e alimentos que vemos em
alguns espaços públicos, precisa de um programa que calcule o troco a ser dado ao cliente
e como fracionar esse troco de acordo com as notas e moedas disponíveis. Escreva um programa
em C que receba da entrada padrão (terminal) um valor em reais (de ponto flutuante) e retorne
quantas notas e moedas de cada valor devem ser dadas como troco. Você deve considerar que o
valor máximo de troco possível é R$ 20.00 e que a máquina armazena notas ou moedas nos valores
de R$ 20.00, R$ 10.00, R$ 5.00, R$ 2.00, R$ 1.00, R$ 0.50, R$ 0.25, R$ 0.10 e R$ 0.05.

Seu algoritmo deve tentar, dentro do possível, minimizar o total de notas ou moedas entregues
como troco, sempre utilizando o máximo possível de notas ou moedas de um valor maior antes de
utilizar notas ou moedas de valor menor. Você pode considerar que a máquina dispõe de quantidade
ilimitada de notas e moedas de cada valor para serem usadas na composição do troco. Na saída,
você deve listar, para cada valor de nota ou moeda, quantas unidades daquela nota ou moeda
devem ser dadas como troco. O formato detalhado da saída é ilustrado abaixo.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com um número
de ponto flutuante t (0 ≤ t ≤ 20), com duas casas decimais, sendo que o valor dos centésimos
sempre será múltiplo de 5.

Saída
A saída deve ser escrita na saída padrão (terminal) em 9 linhas. O formato de cada linha deve
ser dado pelo valor da nota ou moeda considerada (com duas casas decimais) seguida de espaço,
dois pontos, espaço, quantidade de itens desse valor presente no troco e uma quebra de linha. */

#include <stdio.h>

int main() {
    int i;
    float valor, b, c;
    float d1[9] = {20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05};
    
    scanf("%f", &valor);
    b = 1000 * valor;
    
    for (i = 0; i <= 8; i++) {
        c = 1000 * d1[i];
        int d = (int) b / (int) c;
        int e = (int) b % (int) c;
        b = e;
        printf("R$ %.2f : %d\n", d1[i], d);
    }
    
    return 0;
}