#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n;
char array[50000];

int main()
{
	//freopen("input","r",stdin);
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>array[i];
		
	int a = 0, b = n-1, cnt = 0;
	
	while(a <= b)
	{
		bool left = false;
		for(int i = 0; a + i <= b; i++)
		{
			if(array[a+i] < array[b-i])
			{
				left = true;
				break;
			}
			else if(array[a+i] > array[b-i])
				break;
		}
		
		if(left) cout<<array[a++];
		else cout<<array[b--];
		
		cnt ++; 
		if(cnt == 80)
		{
			cout << endl;
			cnt = 0;
		}
	}

	return 0;
 } 
