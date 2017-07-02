#include<iostream>
#include<cstdio>

using namespace std;

#define MAX_E 10000
#define INF 0xfffffff

struct edge{
	int from, to, cost;
}es[MAX_E];

int d[MAX_E];
int V, E;

void shortest_path(int s)
{
	for(int i = 0; i < V; i++)
		d[i] = INF;
	d[s] = 0;
	
	while(true)
	{
		bool update = false;
		for(int i = 0; i < E; i++)
		{
			edge e = es[i];
			if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if(!update) break;
	}
}

int main()
{
	return 0;
 } 
