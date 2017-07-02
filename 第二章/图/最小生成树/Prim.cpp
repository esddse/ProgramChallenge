#include<iostream> 
#include<cstdio>

using namespace std;

int cost[MAX_V][MAX_V]; 
int mincost[MAX_V];     // �Ӽ���x�����ıߵ�ÿ���������СȨֵ
bool used[MAX_V];
int v;

int prim()
{
	fill(mincost, mincost+V, INF);
	fill(used, used+V, false);
	
	mincost[0] = 0;
	int res = 0;
	
	while(true)
	{
		int v = -1;
		// �Ӳ�����x�Ķ�����ѡ����x����Ȩֵ��С�Ķ���
		for(int u = 0; u < V; u++)
			if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		if(v == -1) break;
		
		used[v] = true;
		res += mincost[v];
		
		for(int u = 0; u < V; u++)
			mincost[u] = min(mincost[u], cost[v][u]);	
	}	
	return res
} 
