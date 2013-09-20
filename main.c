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
void Dijkstra(graph *grafo, int start, int end);
int comp(const intDouble_pair a, const intDouble_pair b);

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
			Push_back(&delegacias, input);
		}
		
		for(i = 0; i < SizeVector(delegacias); i++)
			Bfs(&grafo, At(&delegacias, i));
		
		scanf("%d", &n);
		while(n-- > 0)
		{
			scanf("%d %d", &from, &to);
			Dijkstra(&grafo, from, to);
		}
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

void Dijkstra(graph *grafo, int start, int end)
{
	heap q;
    intDouble_pair atual;
    int *pesos = (int*)alloc(SizeGraph(*grafo), sizeof(int));
    int retorno = -1, soma = 0, node;
    unsigned int i = 0;
    
    for(i = 0; i < SizeGraph(*grafo); i++)
        pesos[i] = INF;
    pesos[start] = 0;
    
    InitHeap(&q, comp);
    PushHeap(&q, make_intDoublePair(start, 0.0));
    
    while(EmptyHeap(&q) == 0)
    {
    	atual = FrontHeap(&q);
    	PopHeap(&q);
    	
    	if(atual.first == end)
    	{
    		retorno = pesos[atual.first];
    		break;
    	}
    	
		for(i = 0; i < NumAdjacents(grafo, atual.first); i++)
		{
			node = AdjacentNode(grafo, atual.first, i);
			
		}
    }
    
    free(pesos);
    pesos = NULL;
    /*
    while(!pq.empty())
	{
		atual = *pq.begin();
		pq.erase(pq.begin());
		
		if(atual.second == end) break;
		
		for(vector<PII >::iterator it = (*grafo)[atual.second].begin(); it != (*grafo)[atual.second].end(); it++)
			if(pesos[it->second] > it->first+pesos[atual.second])
			{
				pesos[it->second] = it->first+pesos[atual.second];
				pq.insert(make_pair(pesos[it->second], it->second));
			}
	}
	
	if(pesos[end] != INF)
		return pesos[end];
	else return -1;
    */
}

int comp(const intDouble_pair a, const intDouble_pair b)
{
	return 0;
}
