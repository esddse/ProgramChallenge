#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int len[205][205];

int main()
{
	//freopen("input", "r", stdin);
	
	char s1[205], s2[205];
	while(cin>>s1+1>>s2+1)
	{
		memset(len, 0, sizeof(len));
		int len1 = strlen(s1+1);
		int len2 = strlen(s2+1);
		
		for(int i = 1; i <= len1; i++)
			for(int j = 1; j <= len2; j++)
				len[i][j] = (s1[i] == s2[j]) ? len[i-1][j-1] + 1 : max(len[i-1][j], len[i][j-1]);
	
		cout<<len[len1][len2]<<endl;
	}
	
	return 0;	
} 
