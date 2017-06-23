#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

/*
 关键是两只蚂蚁碰头可以视作两只蚂蚁直接互相穿过 
*/

using namespace std;

int t;
int l, n;

#define MIN_DIR(x) min(x, l-x) 
#define MAX_DIR(x) max(x, l-x) 

int main()
{
	//freopen("input", "r", stdin);
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &l, &n);
		
		int min_time = 0;
		int max_time = 0;
		
		int pos;
		while(n--)
		{
			scanf("%d", &pos);
			
			min_time = max(min_time, MIN_DIR(pos));
			max_time = max(max_time, MAX_DIR(pos));
		}
		printf("%d %d\n", min_time, max_time);
	}
	
	return 0;
} 
