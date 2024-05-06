/* Problema
Imagine que um berçário deseje oferecer uma grande variedade de frutas às crianças sem ter
prejuízo com desperdício comprando frutas que não serão consumidas. Para isso, haverá um
acompanhamento ao longo de 2 meses para um levantamento de qual criança gosta de qual fruta
e o berçário decidirá qual a quantidade de cada fruta comprar a cada semana com base nesse
levantamento. Sua tarefa é fazer um programa em C que, dadas a quantidade de frutas e a
quantidade de crianças presentes no levantamento, imprime um formulário com todas as
combinações de crianças e frutas para que as tias do berçário possam facilmente marcar
a cada dia qual fruta cada criança aceitou ou não comer.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com dois
inteiros, f e c, com 1 ≤ f ≤ 20 e 1 ≤ c ≤ 150, separados por um espaço, sendo que f representa
o número de frutas e c o número de crianças.

Saída
A saída deve ser escrita na saída padrão (terminal) em c * f linhas, cada uma das quais
indicando o par criança e fruta representado pela linha e com espaço para marcação "sim
ou não". O exemplo a seguir ilustra os detalhes de formatação da saída. Observe que as
crianças são numeradas de 1 a c e as frutas de 1 a f. */

#include <stdio.h>

int main() {
    long long int f, c, contador1, contador2;
    scanf("%lld %lld", &f, &c);
    for (contador1 = 1; contador1 <= c; contador1 = contador1 + 1) {
        for (contador2 = 1; contador2 <= f; contador2 = contador2 + 1) {
            printf("Criança %lld ", contador1);
            printf("gosta da fruta %lld: ( )Sim ( )Não\n", contador2);
        }
    }
    return 0;
}