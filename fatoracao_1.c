/* Problema
Todo número inteiro n pode ser fatorado de forma única em fatores primos. Ou seja, podemos
expressar qualquer inteiro n na forma p₁^e₁ · p₂^e₂ · p₃^e₃ · · · pₖ^ek, onde pi representa
o i-ésimo menor inteiro primo e ei representa um expoente inteiro não negativo (pode ser nulo!).
Logo, p1 = 2, p2 = 3, p3 = 5, p4 = 7, e assim por diante. O fator pk é o maior fator primo de
expoente ek não nulo. Dados dois números n e m, o mdc(n, m) é o maior divisor comum a ambos
n e m e o mmc(n, m) é o menor múltiplo comum a ambos n e m. Dadas as fatorações de n e m é
possível encontrar os valores de mdc(n, m) e mmc(n, m). Sua tarefa é fazer um programa que
encontra todos os números primos menores que n e m, a fatoração de n e de m, e o mdc(n, m)
e mmc(n, m) baseado na fatoração dos mesmos.

Entrada
A entrada deve ser lida da entrada padrão (teclado). A entrada contém uma linha com dois inteiros
n e m (1 ≤ n, m ≤ 10^4), separados por espaços.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve conter quatro linhas. A primeira
linha deve conter a fatoração de n com os fatores primos de expoente não nulo em ordem crescente
e seus respectivos expoentes no formato pi ^ ei. A segunda linha deve conter a fatoração de m
com os fatores primos de expoente não nulo em ordem crescente e seus respectivos expoentes no
formato pi ^ ei. A terceira linha deve conter o valor de mdc(n, m). Finalmente, a quarta linha deve
conter o valor de mmc(n, m). */

#include <stdio.h>
#include <math.h>

int main()
{
	long long int n, m, i, j, auxn, auxm;
	long long int vetorn[100000], vetorm[100000];
	long long int raizn, raizm;
	long long int fatoresn[1000], fatoresm[1000];
	
    scanf("%lld %lld", &n, &m);
    raizn = sqrt(n);
    raizm = sqrt(m);
    
    for(i = 2; i <= n; i++){
        vetorn[i] = i;
    }
    
    for (i=2; i<=m; i++){
        vetorm[i] = i;
    }
        
    for(i = 2; i <= raizn; i++){
        if(vetorn[i] == i){
            for(j = i + i; j <= n; j += i){
                vetorn[j] = 0;
            }
        }
    }
    
    for(i = 2; i <= raizm; i++){
        if(vetorm[i] == i){
            for(j = i + i; j <= m; j += i){
                vetorm[j] = 0;
            }
        }
    }
    auxn = n;
    j = 0;
    long long int expn[1000];
    
    for(i = 2; i < n; i++){
		if(vetorn[i] != 0 && auxn % vetorn[i] == 0) {
            fatoresn[j] = vetorn[i];
            j++;
        }
        while(vetorn[i] != 0 && auxn % vetorn[i] == 0){
            expn[j - 1]++;
            auxn = auxn / vetorn[i];
        }
    }
    for(i = 0; i <= j; i++){
    	if(fatoresn[i] == 0){
    		continue;
		}
		else{
			printf("%lld^", fatoresn[i]);
			printf("%lld ", expn[i]);
		}
	}
	printf("\n");

    auxm = m;
    j = 0;
    long long int expm[1000];
	
	for(i = 2; i < m; i++){
		if(vetorm[i] != 0 && auxm % vetorm[i] == 0) {
            fatoresm[j] = vetorm[i];
            j++;
        }
        while(vetorm[i] != 0 && auxm % vetorm[i] == 0){
            expm[j - 1]++;
            auxm = auxm / vetorm[i];
        }
    }
    for(i = 0; i <= j; i++){
    	if(fatoresm[i] == 0){
    		continue;
		}
		else{
			printf("%lld^", fatoresm[i]);
			printf("%lld ", expm[i]);
		}
	}
	printf("\n");	
	long long int menor;
	
    if(n < m){
    	menor = n;
	} else {
		menor = m;
	}
    while (m % menor != 0 || n % menor != 0){
        menor--;
    }
    printf("%lld\n", menor);
    
	for(i = 1; i <= (n * m); i++){
		if(i % n == 0 && i % m == 0){
            printf("%lld\n", i);
            break;
		}
	}
    return 0;
}