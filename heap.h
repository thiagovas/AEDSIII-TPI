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

void InitHeap(heap *obj, int (*func)(const intDouble_pair, const intDouble_pair));
void ClearHeap(heap *obj);
void PushHeap(heap *obj, intDouble_pair value);
intDouble_pair FrontHeap(heap *obj);
void Heapify(heap *obj, int index);
void PopHeap(heap *obj);
int SizeHeap(heap *obj);
int EmptyHeap(heap *obj);
int Left(int i);
int Right(int i);
int Father(int i);
#endif
