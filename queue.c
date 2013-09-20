/*
	Feito por Thiago Vieira
*/

#include "queue.h"

void InitQueue(queue *nodes)
{
	nodes->begin = NULL;
}

void PushQueue(queue *nodes, int_pair newValue)
{
	item_queue *newItem = (item_queue*)alloc(1, sizeof(item_queue));
	newItem->next = nodes->begin;
	newItem->value = newValue;
	nodes->begin = newItem;
}

int EmptyQueue(queue nodes)
{
	return nodes.begin == NULL;
}

int_pair FrontQueue(queue nodes)
{
	/* TODO: Pensar em uma maneira de retornar esse erro */
	if(nodes.begin == NULL) return;
	return nodes.begin->value;
}

void PopQueue(queue *nodes)
{
	if(nodes == NULL || nodes->begin == NULL) return;
	
	item_queue *oldItem = nodes->begin;
	nodes->begin = nodes->begin->next;
	free(oldItem);
}
