#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int n;
int arr[1005]; 
int max_len[1005];

int main()
{
	//freopen("input", "r", stdin);
	
	int max_all = 1;
	
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
		max_len[i] = 1;
		for(int j = 1; j < i; j++)
			if(arr[j] < arr[i])
				max_len[i] = max(max_len[i], max_len[j]+1);
		max_all = max(max_all, max_len[i]);
	}
		
	cout<<max_all;
	
	return 0;
}
