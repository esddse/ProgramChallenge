#include<iostream>
#include<cstdio>

using namespace std;

struct edge{
	int u, v, cost;
};

bool comp(const edge & e1, const edge & e2)
{
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal()
{
	sort(es, es+E, comp);   // 按照edge.cost的顺序从小到大排列
	init_union_find(V);     // 并查集初始化
	int res = 0;
	for(int i = 0; i < E; i++)
	{
		edge e = es[i];
		if(!same(e.u, e.v))
		{
			unit(e.u, e.v);
			res += e.cost;	
		}	
	} 
	return res;
}
