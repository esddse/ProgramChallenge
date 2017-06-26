#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int n; 
int days[25];

int main()
{
	//freopen("input", "r", stdin);
	
	days[1] = 1;
	days[2] = 2;
	for(int i = 3; i < 20; i++)
		days[i] = days[i-1] + days[i-2];
	
	cin>>n;
	cout<<days[n];
	
	return 0;	
} 
