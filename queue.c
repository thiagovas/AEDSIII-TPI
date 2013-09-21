/*
	Feito por Thiago Vieira
*/

#include "queue.h"

void InitQueue(queue *nodes)
{
	nodes->begin = (item_queue*)alloc(1, sizeof(item_queue));
	nodes->begin->next = NULL;
}

void PushQueue(queue *nodes, int_pair newValue)
{
	item_queue *newItem = (item_queue*)alloc(1, sizeof(item_queue));
	nodes->begin->value = newValue;
	newItem->next = nodes->begin;
	nodes->begin = newItem;
}

int EmptyQueue(queue nodes)
{
	return nodes.begin->next == NULL;
}

int_pair FrontQueue(queue nodes)
{
	/* TODO: Pensar em uma maneira de retornar esse erro */
	if(nodes.begin->next == NULL) return make_intpair(-1, -1);
	return nodes.begin->next->value;
}

void PopQueue(queue *nodes)
{
	if(nodes == NULL || nodes->begin == NULL) return;
	
	item_queue *oldItem = nodes->begin;
	nodes->begin = oldItem->next;
	free(oldItem);
}

