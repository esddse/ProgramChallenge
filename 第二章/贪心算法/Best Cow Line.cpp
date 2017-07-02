#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n;
char array[50000];

int cmp(int i, int j)
{
	while( i < j && array[i] == array[j])
	{
		i++;
		j--;
	}
	
	return (array[i] < array[j]) ? 1 : 2;
}

int main()
{
	//freopen("input.txt","r",stdin);
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>array[i];
		
	int head = 0, rear = n-1;
	
	int out_cnt = 0;
	for(int i = 0; i < n; i++)
	{
		int small = cmp(head, rear);
		if(small == 1)
			cout<<array[head++];
		else 
			cout<<array[rear--];
		out_cnt += 1;
		if(out_cnt == 80)
		{
			cout << endl;
			out_cnt = 0;	
		}
		
	}
	
	return 0;
 } 
