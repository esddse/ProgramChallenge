#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>

using namespace std;

/*
做如下思维转换：

“到达加油站加油”变成：
“到达加油站时，获得了在之后任何时候都可以加该加油站油的权利” 

*/

int N, L, P;

struct stop{
	int mile;
	int fuel;
} stops[10005];

bool cmp(stop s1, stop s2){return s1.mile < s2.mile;}

priority_queue<int> pq;

int main()
{
	//freopen("input", "r", stdin); 	
	
	cin>>N;
	for(int i = 1; i <= N; i++)
		cin>>stops[i].mile>>stops[i].fuel;
	cin>>L>>P;
	
	sort(stops, stops+N+1, cmp);
	
	int stopped = 0;
	for(int i = N; i >= 0; i--)
	{
		int d = L - stops[i].mile;
		while(P < d)
		{
			if(pq.empty())
			{
				cout<<-1;
				return 0;
			}
			P += pq.top();pq.pop();
			stopped++;
		}
		
		P -= d;
		pq.push(stops[i].fuel);
		L = stops[i].mile;
	}
	
	cout<<stopped;
	
	return 0;
}
