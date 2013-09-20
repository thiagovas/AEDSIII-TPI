/*
    Feito por Thiago Vieira
*/

#include "heap.h"

/* http://pt.wikipedia.org/wiki/Heap */

/* TODO: Acabar de implementar a heap */

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

void Heapify(heap *obj, int index)
{
	int l = obj->values[Left(index)], r = obj->values[Right(index)];
	int largest;
	
	if(l < SizeHeap(obj) && obj->func(obj->values[l], obj->values[index]))
		largest = l;
	else
		largest = i;
	
	if(r < SizeHeap(obj) && obj->func(obj->values[r], obj->values[largest]))
		largest = r;
}

void Push(heap *obj, intDouble_pair value)
{
	obj->values = (intDouble_pair*) realloc(sizeof(intDouble_pair));
	obj->size += 1;
}

intDouble_pair Front(heap *obj)
{
	/* TODO: Pensar em como retornar esse erro. */
	if(obj == NULL || obj->values == NULL) return;
	
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

int Left(int i)
{
	return (i<<1)+1;
}

int Right(int i)
{
	return Left(i)+1;
}

int Father(int i)
{
	return i>>1;
}
