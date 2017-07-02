#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define OFF(i,j) i*3+j

int N, K, ans = 0;
int d, x, y;

int parent[50005 * 3];
int _rank[50005 * 3];


void init(int n)
{
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
		{
			parent[OFF(i,j)] = OFF(i,j);
			_rank[OFF(i,j)] = 0;	
		}	
}

int find(int x)
{
	if(parent[x] == x)
		return x;
	else 
		return parent[x] = find(parent[x]); 
}

void unit(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x == y) return;
	if(_rank[x] < _rank[y])
		parent[x] = y;
	else
	{
		parent[y] = x;
		if(_rank[x] == _rank[y])
			_rank[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>N>>K;
	
	init(N);
	
	while(K--)
	{
		cin>>d>>x>>y;
		
		if(x <= 0 || x > N || y <= 0 || y > N) 
		{
			ans++;
			continue;
		}
		if(d == 1)
		{
			if(same(OFF(x,0), OFF(y,1)) || same(OFF(x,0), OFF(y,2)))
			{
				ans++;
				continue;
			}
			unit(OFF(x,0), OFF(y,0));
			unit(OFF(x,1), OFF(y,1));
			unit(OFF(x,2), OFF(y,2));
		}
		else
		{
			if(same(OFF(x,0), OFF(y,0)) || same(OFF(x,0), OFF(y,2)))
			{
				ans++;
				continue;
			}
			unit(OFF(x,0), OFF(y,1));
			unit(OFF(x,1), OFF(y,2));
			unit(OFF(x,2), OFF(y,0));
		}
	} 
	
	cout<<ans;
	
	return 0;	
} 
