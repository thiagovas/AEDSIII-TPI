/*
    Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "pair.h"
#include "queue.h"
#include "heap.h"

#define INF 2147000000

void Bfs(graph *grafo, int start);
void Dijkstra(graph *grafo, int start, int end, int k);
int comp(const intDouble_pair a, const intDouble_pair b);
void PrintPath(int *parents, int start, int end);

int main()
{
	graph grafo;
	vector delegacias;
	int numberCases, n, input, i;
	int q, r, d, k;
	double cost;
	int from, to;
	
	scanf("%d", &numberCases);
	while(numberCases-- > 0)
	{
		scanf("%d %d %d %d", &q, &r, &d, &k);
		InitEmptyVector(&delegacias);
		InitGraph(&grafo, q, INF);
		
		while(r-- > 0)
		{
			scanf("%d %d %lf", &from, &to, &cost);
			AddEdge(&grafo, from-1, to-1, cost);
			AddEdge(&grafo, to-1, from-1, cost);
		}
		
		while(d-- > 0)
		{
			scanf("%d", &input);
			Push_back(&delegacias, input-1);
		}
		
		for(i = 0; i < SizeVector(delegacias); i++)
			Bfs(&grafo, At(&delegacias, i));
		
		/*
		for(i = 0; i < SizeGraph(grafo); i++)
			printf("%d: %d\n", i+1, grafo.nodes[i].value);
		*/
		
		scanf("%d", &n);
		while(n-- > 0)
		{
			scanf("%d %d", &from, &to);
			from--; to--;
			Dijkstra(&grafo, from, to, k);
			printf("\n");
		}
		printf("\n");
		ClearGraph(&grafo);
		ClearVector(&delegacias);
	}
	
	return 0;
}

void Bfs(graph *grafo, int start)
{
	queue nodes;
	int_pair atual;
	int i, node;
	vector visited;
	
	InitQueue(&nodes);
	InitVector(&visited, SizeGraph(*grafo), 0); //Inicializo visited com n posições e todas com 0.
	
	PushQueue(&nodes, make_intpair(start, 0));
	while(EmptyQueue(nodes) == 0)
	{
		atual = FrontQueue(nodes);
		PopQueue(&nodes);
		//Se ja visitei esse node eu so pulo para o proximo node da queue;
		if(At(&visited, atual.first) == 1) continue;
		
		if(atual.second < NodeValue(grafo, atual.first))
			EditNodeValue(grafo, atual.first, atual.second);
		
		EditItem(&visited, atual.first, 1);
		for(i = 0; i < NumAdjacents(grafo, atual.first); i++)
		{
			node = AdjacentNode(grafo, atual.first, i);
			if(At(&visited, node) == 0) PushQueue(&nodes, make_intpair(node, atual.second+1));
		}
	}
}

void Dijkstra(graph *grafo, int start, int end, int k)
{
	heap q;
    intDouble_pair atual;
    double *pesos = (double*)alloc(SizeGraph(*grafo), sizeof(int)), prob;
    int *antecedentes = (int*)alloc(SizeGraph(*grafo), sizeof(int));
    int encontrou = 0, node, index;
    unsigned int i = 0;
    
    for(i = 0; i < SizeGraph(*grafo); i++)
        pesos[i] = antecedentes[i] = INF;
    pesos[start] = 0;
    
    InitHeap(&q, comp);
    PushHeap(&q, make_intDoublePair(start, 1.0));
    
    while(EmptyHeap(&q) == 0)
    {
    	atual = FrontHeap(&q);
    	PopHeap(&q);
    	
    	if(ValueFromNode(grafo, atual.first) > k) continue;
    	
    	//printf("%d\n", atual.first+1);
    	if(atual.first == end)
    	{
    		encontrou = 1;
    		break;
    	}
    	
		for(i = 0; i < NumAdjacents(grafo, atual.first); i++)
		{
			node = AdjacentNode(grafo, atual.first, i);
			prob = 1.0-(1.0-CostFromEdge(grafo, atual.first, i))*(1.0-pesos[atual.first]);
			//printf("%d %lf %lf %lf %lf\n", node+1, CostFromEdge(grafo, atual.first, i), prob, 1-prob, pesos[node]);
			if(prob < pesos[node])
			{
				pesos[node] = prob;
				PushHeap(&q, make_intDoublePair(node, pesos[node]));
				antecedentes[node] = atual.first;
			}
		}
    }
    
    if(encontrou)
    {
    	PrintPath(antecedentes, start, end);
    	printf("%.2lf", pesos[end]);
    	printf(" %d", end+1);
    }
    else
    {
    	printf("-1");
    }
    //free(pesos);
    //free(antecedentes);
    //antecedentes = NULL;
    //pesos = NULL;
}

int comp(const intDouble_pair a, const intDouble_pair b)
{
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void PrintPath(int *parents, int start, int end)
{
	if(start == end) return;
	PrintPath(parents, start, parents[end]);
	printf(" %d", parents[end]+1);
}

