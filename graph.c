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
		g->nodes[i].numAdjacents = 0;
	}
}

void AddEdge(graph *g, int FromNode, int ToNode, double cost)
{
	int tam = 0;
	size_t newtam = sizeof(g->nodes[FromNode].edges) + sizeof(edge);
	
 	edge *tempPtr = (edge*)realloc(g->nodes[FromNode].edges, newtam);
 	
 	if(tempPtr == NULL)
 	{
 		// TODO: Printar uma msg de erro.
 		printf("OH\n");
 		free(g->nodes[FromNode].edges);
 	}
 	g->nodes[FromNode].edges = tempPtr;
 	
	tam = NumAdjacents(g, FromNode);
	g->nodes[FromNode].edges[tam].value = -1;
	g->nodes[FromNode].edges[tam].from = FromNode;
	g->nodes[FromNode].edges[tam].to = ToNode;
	g->nodes[FromNode].edges[tam].cost = cost;
	g->nodes[FromNode].numAdjacents += 1;
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
	g->numberNodes= 0;
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
	return g->nodes[node].numAdjacents;
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
