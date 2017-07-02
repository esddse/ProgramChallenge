#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

struct point{
	int x, y;
	int h;
}p[10005];
bool operator < (const point & p1 ,const point & p2) {return p1.h < p2.h;}

int r,c;
int h[105][105];
int len[105][105];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	//freopen("input", "r", stdin);

	cin>>r>>c;

	int k = 0;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
		{
			cin>>h[i][j];
			p[k].x = i; p[k].y = j; p[k++].h = h[i][j];
		}
	
	sort(p, p+k);
	
	int max_len = 0;
	for(int i = 0; i < k; i++)
	{
		len[p[i].x][p[i].y] = 1;
		for(int j = 0; j < 4; j++)
		{
			len[p[i].x][p[i].y] = (p[i].h <= h[p[i].x+dx[j]][p[i].y+dy[j]]) ? len[p[i].x][p[i].y] : max(len[p[i].x][p[i].y], len[p[i].x+dx[j]][p[i].y+dy[j]]+1);
			max_len = max(max_len, len[p[i].x][p[i].y]);
		}
	}
	
	cout<<max_len;

	return 0;
} 
