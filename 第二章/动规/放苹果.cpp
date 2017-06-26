#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int m, n, t; 
int apple[11][11];

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		memset(apple, 0, sizeof(apple));
		
		for(int i = 1; i <= m; i++)
			apple[i][1] = 1;
		for(int j = 1; j <= n; j++)
			apple[1][j] = 1, apple[0][j] = 1;
		
		for(int i = 2; i <= m; i++)
			for(int j = 2; j <= n; j++)
				apple[i][j] = (i < j) ? apple[i][j-1] : apple[i][j-1] + apple[i-j][j];
				
		cout<<apple[m][n]<<endl;
	}
	
	return 0;
} 
