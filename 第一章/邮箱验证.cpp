#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	//freopen("input", "r", stdin);
	
	string addr;
	while(cin>>addr)
	{
		int len = addr.size(), dot = 0;
		bool at = false, br = false;
		if(addr[0] == '@' || addr[0] == '.' || addr[len-1] == '@' || addr[len-1] == '.')
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 1; i < len-1; i++)
		{
			if(addr[i] == '@')
			{
				if(at || addr[i+1] == '.' || addr[i-1] == '.')
				{
					br = true;
					break;
				}
				at = true;
			}
			else if(addr[i] == '.')
				if(!at) continue;
				else dot++;
		}	
		if(br || dot < 1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	
	return 0;	
} 
