/*
    Feito por Thiago Vieira
*/

#ifndef _graph_h
#define _graph_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "vector.h"

typedef struct{
	int value;
	int from, to;
	double cost;
} edge;

typedef struct{
	edge *edges;
	int value;
} node;

typedef struct{
	node *nodes;
	int numberNodes; //Number of nodes
} graph;

void InitGraph(graph *g, int nNodes, int defaultValue);
void AddEdge(graph *g, int FromNode, int ToNode, double cost);
void ClearGraph(graph *g);
int SizeGraph(graph g);
int NumAdjacents(graph *g, int node);
int NodeValue(graph *g, int node);
void EditNodeValue(graph *g, int node, int newValue);

#endif
