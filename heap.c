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

void ClearHeap(heap *obj)
{
	if(obj->values == NULL) return;
	
	free(obj->values);
	obj->values = NULL;
}

void Heapify(heap *obj, int index)
{
	int l = Left(index), r = Right(index);
	int largest;
	intDouble_pair temp;
	
	if(l < SizeHeap(obj) && obj->func(obj->values[l], obj->values[index]))
		largest = l;
	else
		largest = index;
	
	if(r < SizeHeap(obj) && obj->func(obj->values[r], obj->values[largest]))
		largest = r;
	
	if(largest != index)
	{
		temp = obj->values[largest];
		obj->values[largest] = obj->values[index];
		obj->values[index] = temp;
		
		Heapify(obj, largest);
	}
}

void PushHeap(heap *obj, intDouble_pair value)
{
	int index = SizeHeap(obj);
	intDouble_pair *temp = (intDouble_pair*) realloc(obj->values, (SizeHeap(obj)+1)*sizeof(intDouble_pair));
	intDouble_pair swap;
	
	if(temp == NULL)
	{
		// TODO: Pensat em uma mensagem de erro.
		// Se temp for null, quer dizer que a alocação de memória não foi feita com sucesso.
		free(obj->values);
	}
	
	obj->values = temp;
	obj->values[obj->size] = value;
	obj->size += 1;
	
	while(index > 0 && obj->func(obj->values[Father(index)], obj->values[index]))
	{
		swap = obj->values[Father(index)];
		obj->values[Father(index)] = obj->values[index];
		obj->values[index] = swap;
		index = Father(index);
	}
}

intDouble_pair FrontHeap(heap *obj)
{
	return obj->values[0];
}

void PopHeap(heap *obj)
{
	obj->values[0] = obj->values[SizeHeap(obj)-1];
	obj->size -= 1;
	obj->values = realloc(obj->values, SizeHeap(obj)*sizeof(intDouble_pair));
	Heapify(obj, 0);
}

int SizeHeap(heap *obj)
{ return obj->size; }

int EmptyHeap(heap *obj)
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
