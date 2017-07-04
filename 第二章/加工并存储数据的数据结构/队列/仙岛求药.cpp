#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int m, n;
char map[25][25]; 
bool used[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct P{
	int x, y;
	int step;
	P(int a, int b, int c):x(a), y(b), step(c){}
};

int main()
{
	//freopen("input", "r", stdin);
	
	while(cin>>m>>n)
	{
		if(m == 0) break;
		
		bool flag = false;
		queue<P> q;
		memset(used, 0, sizeof(used));

		char c;
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++)
			{
				cin>>c;
				if(c == '@') q.push(P(i, j, 0)), used[i][j] = true;
				else map[i][j] = c;	
			}
		
	
		while(!q.empty())
		{
			P p = q.front(); q.pop();
			for(int i = 0; i < 4; i++)
			{
				int next_x = p.x + dx[i];
				int next_y = p.y + dy[i];
				
				if (next_x < 1 || next_x > m || next_y < 1 || next_y > n) continue;
				
				if(!used[next_x][next_y])
				{
					if(map[next_x][next_y] == '*')
					{
						cout<<p.step+1<<endl;
						flag = true;
						break;
					}
					else if(map[next_x][next_y] == '.')
						q.push(P(next_x, next_y, p.step+1));
					used[next_x][next_y] = true;
				} 	
			} 
			if(flag) break;
		}
		
		if(flag) continue;
		
		cout<<-1<<endl;
	}
	
	return 0;	
} 
