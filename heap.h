/*
    Feito por Thiago Vieira
*/

#ifndef _heap_h
#define _heap_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pair.h"

typedef struct{
	intDouble_pair *values;
	int size;
	
	/* http://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c */
	int (*func)(const intDouble_pair, const intDouble_pair); // Função usada para montar a heap. Nesse tp vou usar só um min ou max.
} heap;

/*
	TODO:
		Init
		Clear
		Push
		Pop
		Size
		Empty
*/

void InitHeap(heap *obj, );
void Clear(heap *obj);
void Push(heap *obj, int value);
int Front(heap *obj);
void Pop(heap *obj);
int SizeHeap(heap *obj);
int Empty(heap *obj);
#endif
