#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int n, t, cnt0 = 0, cnt = 0;
int area[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void explore(int x, int y)
{
	cnt++;
	area[x][y] = 0;
	for(int i = 0; i < 4; i++)
		if(area[x+dx[i]][y+dy[i]] == 255)
			explore(x+dx[i], y+dy[i]);
}

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			cin>>area[i][j];
			if(area[i][j] == 0) cnt0++;
		}
	
	for(int i = 1; i <= n; i++)
	{
		if(area[1][i] == 255) explore(1, i);
		if(area[i][1] == 255) explore(i, 1);
		if(area[n][i] == 255) explore(n, i);
		if(area[i][n] == 255) explore(i, n);
	} 
	
	cout<<n*n-cnt0-cnt;
	
	return 0; 
} 
