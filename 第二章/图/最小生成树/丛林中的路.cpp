#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define MAX_V 30
#define INF 0xfffffff
 
int n;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];


int main()
{
	//freopen("input", "r", stdin);
	
	while(cin>>n)
	{
		if(n == 0) break;
		
		for(int i = 0; i < n; i++)
			fill(cost[i], cost[i]+n, INF);
		fill(mincost, mincost+n, INF);
		fill(used, used+n, false);
		
		for(int i = 0; i < n-1; i++)
		{
			char c, c2; 
			int m, c2_cost;
			cin>>c>>m;
			while(m--)
			{
				cin>>c2>>c2_cost;
				cost[c-'A'][c2-'A'] = cost[c2-'A'][c-'A'] = c2_cost;
			}	
		}
		
		int res = 0;
		mincost[0] = 0;
		while(true)
		{
			int v = -1;
			for(int u = 0; u < n; u++)
				if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
			
			if(v == -1) break;
			
			used[v] = true;
			res += mincost[v];
			
			for(int u = 0; u < n; u++)
				if(mincost[u] > cost[v][u])
					mincost[u] = cost[v][u];
		}
		cout<<res<<endl;
	}
	
	return 0;
} 
