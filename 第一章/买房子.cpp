#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int n, k;

int main()
{
	//freopen("input", "r", stdin);	
	
	cin>>n>>k;
	
	float m = 200;
	for(int i = 1; i <= 20; i++)
	{
		if(i > 1) m += ((float)k / 100.0) * m;
		int s = i*n;
		if(s >= m)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<"Impossible";
	
	return 0;
} 
