#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int N, M;
char m[105][105];
bool mark[105][105];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

void explore(int x, int y)
{
	mark[x][y] = true;
	for(int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < N && ny >= 0 && ny < M && m[nx][ny] == 'W' && !mark[nx][ny])
			explore(nx, ny); 
	}
}

int main()
{
	//freopen("input", "r", stdin);
	cin>>N>>M; 
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin>>m[i][j];
	
	int cnt = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(m[i][j] == 'W' && !mark[i][j])
			{
				explore(i, j);
				cnt ++;
			}
				
	printf("%d\n", cnt);
	
	return 0;
 } 
