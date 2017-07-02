#include<iostream>
#include<cstdio> 

using namespace std;

int cost[MAX_V][MAX_V]; // cost[u][v] ��ʾ�� e = (u, v) ��Ȩֵ 
int d[MAX_V];           // ����s��������̾��� 
bool used[MAX_V];       // �Ѿ�ʹ�ù���ͼ 
int V;                  // ������ 

void dijkstra(int s)
{
	fill(d, d+V, INF);
	fill(used, used+V, false);
	d[s] = 0;
	
	while(true)
	{
		int v = -1;
		// ����δʹ�õĶ�����ѡ��һ��������С�Ķ���
		for(int u = 0; u < V; u++)
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		if(v == -1) break;
		
		used[v] = true;
		for(int u = 0; u < V; u++)
			d[u] = min(d[u], d[v] + cost[v][u]);
		
	}	
} 
 

int main()
{
	return 0;
} 
