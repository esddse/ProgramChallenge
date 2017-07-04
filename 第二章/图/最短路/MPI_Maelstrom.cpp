#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define MAX_N 105
#define INF 0xfffffff

int n;
int d[MAX_N];
bool used[MAX_N];
int cost[MAX_N][MAX_N];

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n;
	fill(d, d+n+1, INF);
	fill(used, used+n+1, false);
	for(int i = 1; i <= n; i++)
		cost[i][i] = 0;
	
	char input[100];
	int c;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++)
		{
			cin>>input;
			if(input[0] == 'x') c = INF;
			else c = atoi(input);	
			cost[i][j] = cost[j][i] = c;
		} 
	
	
	d[1] = 0;
	while(true)
	{
		int v = -1;
		for(int i = 1; i <= n; i++)
			if(!used[i] && (v == -1 || d[i] < d[v])) v = i;
		if(v == -1) break;
		
		used[v] = true;
		for(int i = 1; i <= n; i++)
			d[i] = min(d[i], d[v] + cost[v][i]);
	}
	
	cout<<*max_element(d+1, d+n+1); 
	
	return 0;
}
