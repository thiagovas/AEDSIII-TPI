/*
    Feito por Thiago Vieira
*/

#include "heap.h"

/* http://pt.wikipedia.org/wiki/Heap */

void InitHeap(heap *obj, int (*func)(const intDouble_pair, const intDouble_pair))
{
	obj->size = 0;
	obj->values = NULL;
	obj->func = func;
}

void Clear(heap *obj)
{
	if(obj->values == NULL) return;
	
	free(obj->values);
	obj->values = NULL;
}

void Push(heap *obj, intDouble_pair value)
{
	
	obj->size += 1;
}

intDouble_pair Front(heap *obj)
{
	if(obj == NULL || obj->values == NULL) return NULL;
	
	return obj->values[0];
}

void Pop(heap *obj)
{
	
}

int SizeHeap(heap *obj)
{
	return obj->size;
}

int Empty(heap *obj)
{
	return obj->size == 0;
}