/* Considere um grafo (não direcionado) G de N vértices e M arestas onde cada
vértice é identificado por um número único de (0 . . . N −1). Dizemos que G é
conexo se todo par de vértices u e v é ligado por um caminho. Quando G não é
conexo, possui componentes conexas. Desejamos computar o número de componentes
conexas de um grafo G especificado. Um subgrafo H de G é maximal conexo se
nenhum supergrafo de H que é subgrafo de G é conexo. As componentes conexas
de G são precisamente os subgrafos maximais conexos de G. Note que a relação
de existir caminho entre um par de vértices u e v de um grafo é uma relação
de equivalência e cada componente conexa forma uma classe de equivalência.

Entrada
A entrada deve ser lida da entrada padrão (teclado). As duas primeiras linhas
serão respectivamente o número de vértices N do grafo G onde N ≤ 500 e o número
de arestas M do grafo G. Então as próximas M linhas representarão cada aresta
deste grafo no formato U V, sendo respectivamente os extremos da aresta.

Saída
A saída deve ser escrita na saída padrão (terminal). A saída deve ser apenas o
número correspondente à quantidade de componentes conexas do grafo. */

#include <stdio.h>
#define MAX 500

/* Aqui se utiliza a busca em profundidade para encontrar a quantidade de componentes
conexas do grafo em questão. Chama-se a busca em profundidade para todos os vértices,
marca os vértices que são visitados. Assim, toda vez que chama dfs significa que esse
vértice não foi visitado, então se não foi visitado, pertence a outra componente
conexa, marcando assim sempre que passa pela função dfs recursivamente. E quando
"comp" não foi alterado, então está em outra componente conexa e se incrementa
esse número que será o resultado final. */

void dfs(int graph[MAX][MAX], int comp[], int i, int N){
	comp[i] = 1;
	for(int j = 0; j < N; j++){
		if(graph[i][j] == 1){
			if(comp[j] == 0){
				dfs(graph, comp, j, N);
			}
		}	
	}
}

void qtd_comp(int graph[MAX][MAX], int N){
	int comp[N];
	int num_comp = 0;
	for(int i = 0; i < N; i++){
		comp[i] = 0;
	}
	for(int i = 0; i < N; i++){
		if(comp[i] == 0){
			dfs(graph, comp, i, N);
			num_comp++;
		}
	}
	printf("%d\n", num_comp);
}

int main(int argc,char *argv[])
{
	int N, M;
	
	scanf("%d", &N);
	scanf("%d", &M);
	
	int graph[MAX][MAX];
	
	for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++){
	    	graph[i][j] = 0;
	    }
	}
	
	int U, V;
	
	for(int i = 0; i < M; i++){
		scanf("%d %d", &U, &V);
		graph[U][V] = 1;
		graph[V][U] = 1;
	}
	
	/*for(int i = 0; i < N; i++){
	    for(int j = 0; j < N; j++){
	    	printf("%d ", graph[i][j]);
	    }
	    printf("\n");
	}*/
	
	qtd_comp(graph, N);
	return 0;
}