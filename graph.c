#include "graph.h"

void InitGraph(graph *g, int nNodes, int defaultValue)
{
	int i = 0;
	g->numberNodes = nNodes;
	g->nodes = (node*)alloc(nNodes, sizeof(node));
	
	for(i = 0; i < nNodes; i++)
	{
		g->nodes[i].value = defaultValue;
		g->nodes[i].edges = NULL;
	}
}

void AddEdge(graph *g, int FromNode, int ToNode, double cost)
{
	int tam = 0;
	g->nodes[FromNode].edges = (edge*)realloc(g->nodes[FromNode].edges, sizeof(g->nodes[FromNode].edges) + sizeof(edge));
	tam = NumAdjacents(g, FromNode);
	g->nodes[FromNode].edges[tam-1].value = -1;
	g->nodes[FromNode].edges[tam-1].from = FromNode;
	g->nodes[FromNode].edges[tam-1].to = ToNode;
	g->nodes[FromNode].edges[tam-1].cost = cost;
}

void ClearGraph(graph *g)
{
	int i = 0;
	for(i = 0; i < g->numberNodes; i++)
	{
		free(g->nodes[i].edges);
		g->nodes[i].edges = NULL;
	}
	free(g->nodes);
	g->nodes = NULL;
	free(g);
	g->numberNodes= 0;
	g = NULL;
}

int SizeGraph(graph g)
{ return g.numberNodes; }

int AdjacentNode(graph g, int FromNode, int index)
{
	if(FromNode < 0) return -1;
	if(g.nodes == NULL || g.nodes[FromNode].edges == NULL) return -1;
	if(index < 0 || index >= NumAdjacents(&g, FromNode)) return -1;
	
	return g.nodes[FromNode].edges[index].to;
}

int NumAdjacents(graph *g, int node)
{
	return sizeof(g->nodes[node].edges) / sizeof(g->nodes[node].edges[0]);
}

int NodeValue(graph *g, int node)
{
	if(node < 0 || node >= g->numberNodes) return -1;	
	return g->nodes[node].value;
}

void EditNodeValue(graph *g, int node, int newValue)
{
	g->nodes[node].value = newValue;
}
