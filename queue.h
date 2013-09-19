/*
	Feito por Thiago Vieira
*/

#ifndef _queue_h
#define _queue_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pair.h"
#include "vector.h"

typedef struct itemqueue{
	int_pair value;
	struct itemqueue *next;
} item_queue;

typedef struct{
	item_queue *begin;
} queue;

void InitQueue(queue *nodes);
void PushQueue(queue *nodes, int_pair newValue);
int EmptyQueue(queue nodes);
int_pair FrontQueue(queue nodes);
void PopQueue(queue *nodes);

#endif
