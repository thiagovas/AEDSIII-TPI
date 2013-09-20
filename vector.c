/*
    Feito por Thiago Vieira
*/
#include "vector.h"

/* Função que aloca n posições de nBytes bytes e retorna um ponteiro de void. */
void* alloc(int n, size_t nBytes)
{
    void *ptr = calloc(n, nBytes);
    if(ptr == NULL)
    {
        printf("Error: Memoria insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void InitVector(vector *obj, int size, int defaultValue)
{
	int i = 0;
	obj->sizeObj = size;
	obj->list = (item*)alloc(size, sizeof(item));
	
	for(i = 0; i < size; i++)
		obj->list[i].value = defaultValue;
}

void InitEmptyVector(vector *obj)
{
	obj->sizeObj = 0;
	obj->list = NULL;
}

void Push_back(vector *obj, int value)
{
	obj->list = (item*)realloc(obj->list, (obj->sizeObj + 1)*sizeof(item));
	obj->list[obj->sizeObj].value = value;
	obj->sizeObj += 1;
}

void Push_front(vector *obj, int value)
{
	int i = 0;
	obj->list = (item*)realloc(obj->list, (obj->sizeObj + 1)*sizeof(item));
	
	for(i = obj->sizeObj; i > 0; i++)
		obj->list[i] = obj->list[i-1];
	obj->list[0].value = value;
	
	obj->sizeObj += 1;
}

void Pop_back(vector *obj)
{
	obj->list = (item*)realloc(obj->list, (obj->sizeObj - 1)*sizeof(item));
	obj->sizeObj -= 1;
}

void PrintVector(vector obj)
{
	if(obj.sizeObj == 0) return;
	
	int i = 1;
	
	printf("%d", obj.list[0].value);
	for(i = 1; i < obj.sizeObj; i++)
		printf(" %d", obj.list[i].value);
	printf("\n");
}

int SizeVector(vector obj)
{ return obj.sizeObj; }

void ClearVector(vector *obj)
{
	obj->sizeObj = 0;
	free(obj->list);
	obj->list = NULL;
	obj = NULL;
}

int At(vector *obj, int index)
{
	return obj->list[index].value;
}

void EditItem(vector *obj, int index, int newValue)
{
	obj->list[index].value = newValue;
}
