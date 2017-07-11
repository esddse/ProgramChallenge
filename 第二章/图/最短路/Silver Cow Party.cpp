#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define MAX_N 1005
#define INF 0xfffffff

int m, n, x, a, b, t;
typedef pair<int, int> P;   // (min_dis, to)
struct edge{int to, cost; edge(int t, int c): to(t), cost(c){}};
vector<edge> G[MAX_N], r_G[MAX_N];
int D[MAX_N], r_D[MAX_N];

void dijkstra(vector<edge> *g, int *d, int k)
{
	priority_queue<P, vector<P>, less<P> > pq;
	pq.push(P(0, k));
	
	while(!pq.empty())
	{
		P p = pq.top(); pq.pop();
		if(d[p.second] < p.first) continue;
		d[p.second] = p.first;
		
		for(int i = 0; i < g[p.second].size(); i++)
		{
			edge e = g[p.second][i];
			if(d[e.to] > d[p.second] + e.cost)
				pq.push(P(d[p.second] + e.cost, e.to));
		}
	}
}

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n>>m>>x;
	
	fill(D, D+n+1, INF);
	fill(r_D, r_D+n+1, INF);
	
	while(m--)
	{
		cin>>a>>b>>t;
		G[a].push_back(edge(b, t));
		r_G[b].push_back(edge(a, t));
	}
	
	dijkstra(G, D, x);
	dijkstra(r_G, r_D, x);
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, D[i]+r_D[i]);
	
	cout<<ans;
	
	return 0;
 } 
