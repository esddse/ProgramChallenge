#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

#define MAX_N 105
#define INF 0xfffffff

struct edge{
	int to, cost;
	edge(){} 
	edge(int t, int c): to(t), cost(c){} 
};

typedef pair<int, int> P; // first×î¶Ì¾àÀë, second¶¥µãºÅ 

int n;
int d[MAX_N];
vector<edge> graph[MAX_N];

priority_queue<P, vector<P>, less<P> > pq;

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n;
	fill(d, d+n+1, INF);
	char input[100];
	int cost;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++)
		{
			 cin>>input;
			 if(input[0] == 'x') cost = INF;
			 else cost = atoi(input);
			 graph[i].push_back(edge(j, cost));
			 graph[j].push_back(edge(i, cost));
		}
	
	pq.push(P(0, 1));
	
	while(!pq.empty())
	{
		P p = pq.top();pq.pop();
		if(d[p.second] < p.first) continue;
		d[p.second] = p.first;
		
		for(int i = 0; i < graph[p.second].size(); i++)
		{
			edge e = graph[p.second][i];
			if(d[e.to] > d[p.second] + e.cost)
				pq.push(P(d[p.second] + e.cost, e.to));
		}
	}	
	
	cout<<*max_element(d+1, d+n+1);
	
	return 0;
 } 
