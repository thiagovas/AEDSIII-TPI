/*
    Feito por Thiago Vieira
*/

#ifndef _vector_h
#define _vector_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
	int value;
} item;

typedef struct{
	item *list;
	int sizeObj; //Size of this object
} vector;

/*
	TODO:
		Init  ---> With an boolean parameter asking if the vector is ordened or not, and another parameter that receives an function.
		Push_back
		Push_front
		Find
		Count
		Clear
		At
*/

/* Função que aloca n posições de nBytes bytes e retorna um ponteiro de void. */
void* alloc(int n, size_t nBytes);
void InitVector(vector *obj, int size, int defaultValue);
void InitEmptyVector(vector *obj);
void Push_back(vector *obj, int value);
void Push_front(vector *obj, int value);
void Find(vector *obj, int value);
int SizeVector(vector obj);
void ClearVector(vector *obj);
int At(vector *obj, int index);
void EditItem(vector *obj, int index, int newValue);

#endif
