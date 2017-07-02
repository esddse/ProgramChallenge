#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int r, n;
int xs[1005];

int main()
{
	//freopen("input", "r", stdin);
	
	while(cin>>r>>n)
	{
		if(r == -1)
			break;
		for(int i = 0; i < n; i++)
			cin>>xs[i];
		
		sort(xs, xs+n);
		
		int start = 0, cnt = 0;
		while(start < n)
		{
			cnt ++;
			
			int i = start + 1;
			while(i < n && xs[start] + r >= xs[i]) i++;		
			start = --i;
			while(start < n && xs[i] + r >= xs[start]) start++;
		}
		cout << cnt << endl;
	}
	
	return 0;
}
