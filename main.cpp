#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int i, q, r, d, k;
	int u, v;
	double cost;
	vector<vector<pair<double, int> > > grafo;
	
	scanf("%d", &i);
	while(i-- > 0)
	{
		scanf("%d %d %d %d", &q, &r, &d, &k);
		
		grafo.clear();
		grafo.resize();
		while(r-- > 0)
		{
			scanf("%d %d %lf", &u, &v, &cost);
			
		}
	}
	return 0;
}
