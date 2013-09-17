/*
    Feito por Thiago Vieira
*/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "pair.h"

void Bfs(graph *grafo, int start);
void Dijkstra(graph *grafo, int start, int end);

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
		InitGraph(&grafo, q);
		
		while(r-- > 0)
		{
			scanf("%d %d %lf", &from, &to, &cost);
			AddEdge(&grafo, from, to, cost);
			AddEdge(&grafo, to, from, cost);
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
	int atual;
	vector visited;
	
	InitVector(&visited, SizeGraph(*grafo), 0); //Inicializo visited com n posições e todas com 0.
	
	
	
	/*
	queue<int> nodes;
	int atual;
	vector<bool> visited(grafo->size(), false);
	
	while(!nodes.empty())
	{
		atual = nodes.front();
		nodes.pop();
		if(visited[atual]) continue;
		
		for(vector<int>::iterator it = (*grafo)[atual].begin(); it != (*grafo)[atual].end(); it++)
			if(!visited[*it]) nodes.push(*it);
	}
	*/
}

void Dijkstra(graph *grafo, int start, int end)
{
    heap q;
    intDouble_pair atual;
    int *pesos = (int*)calloc(grafo->size(), sizeof(int));
    int retorno = -1, soma = 0;
    
    for(unsigned int i = 0; i < grafo->size(); i++)
        pesos[i] = -1;
    pesos[start] = 0;
    
    Push(&q, make_pair(0, start));
    
    while(!q.empty())
    {
        atual = q.top();
        q.pop();
        
        if(atual.second == end)
        {
            retorno = pesos[atual.second];
            break;
        }
        soma = pesos[atual.second];
        
        for(vector<pair<int, int> >::iterator i = (*grafo)[atual.second].begin(); i != (*grafo)[atual.second].end(); i++)
        {
            if(pesos[i->second] == -1) q.push(make_pair(soma+(i->first), i->second));
            
            if(((pesos[i->second] > soma+(i->first)) && (pesos[i->second] != 0)) || pesos[i->second] == -1)
                pesos[i->second] = soma+(i->first);
        }
    }
    free(pesos);
    return retorno;
}
