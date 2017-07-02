#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

/*
HuffmanÊ÷ 
*/

int n;
priority_queue<int, vector<int>, greater<int> > ls;

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n;
	int l;
	for(int i = 0; i < n; i++)
	{
		cin>>l;
		ls.push(l);
	}

	long long sum = 0;
	while(ls.size() > 1)
	{
		int min1 = ls.top();ls.pop();
		int min2 = ls.top();ls.pop();
		sum += min1 + min2;
		ls.push(min1 + min2);
	}
	cout<<sum;
	
	return 0;
 } 
