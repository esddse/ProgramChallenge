#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N, L, P;
int miles[10005];
int fuels[10005];

struct state{
	int mile_left;
	int fuel_left;
	int stopped;
	
	state(){}
	state(int m, int f, int s): mile_left(m), fuel_left(f), stopped(s) {}
	bool operator < (const state &s) const {return stopped > s.stopped;}; 
};


priority_queue<state> pq;

int main()
{
	//freopen("input", "r", stdin);	
	
	cin>>N;
	for(int i = 0; i < N; i++)
		cin>>miles[i]>>fuels[i];
	cin>>L>>P;
	
	state start = *(new state(L, P, 0));
	pq.push(start);
	
	while(!pq.empty())
	{
		state s = pq.top(); pq.pop();
		if(s.fuel_left >= s.mile_left)
		{
			cout<<s.stopped;
			return 0;
		}
		int min_dis = s.mile_left - s.fuel_left;
		for(int i = 0; i < N; i++)
			if (miles[i] < s.mile_left && miles[i] >= min_dis)
				pq.push(*(new state(miles[i], s.fuel_left-(s.mile_left-miles[i])+fuels[i], s.stopped+1)));
	}
	
	cout<<-1;
	
	return 0;
} 
