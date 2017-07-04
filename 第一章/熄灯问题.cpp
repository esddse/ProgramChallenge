#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

bool lamp[7][8];
bool bt[7][8];

int main()
{
	//freopen("input", "r", stdin);
	
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 6; j++)
			cin>>lamp[i][j];
			
	for(int num = 0; num < 64; num++)
	{
		bool flag = false;
		for(int i = 0; i < 6; i++)
			bt[1][i+1] = (num >> i) & 1;
		
		for(int i = 2; i <= 5; i++)
			for(int j = 1; j <= 6; j++)
				bt[i][j] = (lamp[i-1][j] + bt[i-2][j] + bt[i-1][j-1] + bt[i-1][j] + bt[i-1][j+1]) & 1;	 
		for(int i = 1; i <= 6; i++)
			if((lamp[5][i] + bt[5][i] + bt[5][i-1] + bt[5][i+1] + bt[4][i]) & 1)
			{
				flag = true;
				break;
			}
		if(flag) continue;
		
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 6; j++)
				cout<<bt[i][j]<<" ";
			cout<<endl;
		}
		break;
	}
	
	return 0;	
} 
