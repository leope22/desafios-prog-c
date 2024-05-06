/* Problema
Todo número inteiro n pode ser fatorado de forma única em fatores primos. Ou seja, podemos
expressar qualquer inteiro n na forma p₁^e₁ · p₂^e₂ · p₃^e₃ · · · pₖ^ek, onde pi representa o i-ésimo
menor inteiro primo e ei representa um expoente inteiro não negativo (pode ser nulo!). Logo,
p₁ = 2, p₂ = 3, p₃ = 5, p₄ = 7, e assim por diante. O fator pk é o maior fator primo de expoente
ek não nulo. Dados dois números n e m, o mdc(n, m) é o maior divisor comum a ambos n e m e o
mmc(n, m) é o menor múltiplo comum a ambos n e m. Sua tarefa é fazer um programa que encontra
o mdc(n, m) e mmc(n, m) baseado no algoritmo de Euclides.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com dois inteiros
n e m (1 ≤ n, m ≤ 10^9), separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve conter duas linhas. A primeira
linha deve conter o valor de mdc(n, m) e a segunda linha deve conter o valor de mmc(n, m). */

#include <stdio.h>

int main(){

    long long int num1, num2, resto = 1, auxnum1, auxnum2;
	
    scanf("%lld", &num1);
    scanf("%lld", &num2);
	
    auxnum1 = num1;
    auxnum2 = num2;

    while(resto != 0){
        resto = auxnum1 % auxnum2;
        auxnum1 = auxnum2;
        auxnum2 = resto;
    }
	
    printf("%lld\n", auxnum1);
    printf("%lld\n", (num1 * num2) / auxnum1);
    
    return 0;
}