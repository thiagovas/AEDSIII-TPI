#include "graph.h"

/* TODO: Alterar toda esse .c, porque eu alterei a estrutura de dados graph em graph.h */

void InitGraph(graph *g, int nNodes)
{
	int i = 0;
	g->numberNodes = nNodes;
	g->nodes = alloc(nNodes, sizeof(edge*));
}

void AddEdge(graph *g, int FromNode, int ToNode, double cost)
{
	int tam = 0;
	g->nodes[FromNode] = realloc(g->nodes[FromNode], sizeof(g->nodes[FromNode]) + sizeof(edge));
	tam = sizeof(g->nodes[FromNode]) / sizeof(g->nodes[FromNode][0]);
	g->nodes[FromNode][tam-1].value = -1;
	g->nodes[FromNode][tam-1].from = FromNode;
	g->nodes[FromNode][tam-1].to = ToNode;
	g->nodes[FromNode][tam-1].cost = cost;
}

void RemoveEdge(graph *g, int FromNode, int ToNode)
{
	
}

void ClearGraph(graph *g)
{
	int i = 0;
	for(i = 0; i < g->numberNodes; i++)
	{
		free(g->nodes[i]);
		g->nodes[i] = NULL;
	}
	free(g);
	g->numberNodes= 0;
	g = NULL;
}

int SizeGraph(graph g)
{ return g.numberNodes; }
