#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int T, M;
int t[105];
int v[105]; 
int r[105][1005];

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>T>>M;
	for(int i = 1; i <= M; i++)
		cin>>t[i]>>v[i];

	for(int i = 1; i <= M; i++)
		for(int j = 1; j <= T; j++)
			r[i][j] = (j < t[i]) ? r[i-1][j] : max(r[i-1][j-t[i]] + v[i], r[i-1][j]);
		

	cout<<r[M][T];
		
	return 0;
}
