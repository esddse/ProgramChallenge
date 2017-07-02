#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int n;
int vec[105]; 
int s[105];
int mat[105][105];

int sum(int i, int k, int l)
{
	int s = 0;
	for(int j = k; j < k+l; j++)
		s += mat[i][j];
	return s;
}

int main()
{
	//freopen("input", "r", stdin);

	cin>>n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>mat[i][j]; 
	
	int max_val = -9999999;
	for(int l = 1; l <= n; l++)
	{
		for(int k = 1; k <= n-l+1; k++)
		{
			memset(s, 0, sizeof(s));
			for(int i = 1; i <= n; i++)
			{
				vec[i] = sum(i, k, l);
				s[i] = max(s[i], s[i-1]+vec[i]);
				max_val = max(max_val, s[i]);
			}
		}
	}
	
	cout<<max_val;

	return 0; 
} 
