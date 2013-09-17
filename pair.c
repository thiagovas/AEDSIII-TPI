/*
	Feito por Thiago Vieira
*/

#include "pair.h"

intDouble_pair make_intDoublePair(int a, double b)
{
	intDouble_pair new_pair;
	new_pair.first = a;
	new_pair.second = b;
	return new_pair;
}

int_pair make_intpair(int a, int b)
{
	int_pair new_pair;
	new_pair.first = a;
	new_pair.second = b;
	return new_pair;
}

void_pair make_voidpair(void *a, void *b)
{
	void_pair new_pair;
	new_pair.first = a;
	new_pair.second = b;
	return new_pair;
}
