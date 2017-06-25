#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>

using namespace std;

int n;

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n;
	
	multiset<int> s;
	set<int> r; 
	
	while(n--)
	{
		string cmd;
		cin>>cmd;
		
		if(cmd == "add")
		{
			int x;
			cin>>x;
			s.insert(x);
			r.insert(x);
			cout<<s.count(x)<<endl;
		}
		else if(cmd == "ask")
		{
			int x;
			cin>>x;
			set<int>::iterator it = r.find(x);
			if(it == r.end())
				cout<<0<<" "; 
			else
				cout<<1<<" ";
			cout<<s.count(x)<<endl;
		}
		else if(cmd == "del")
		{
			int x;
			cin>>x;
			cout<<s.count(x)<<endl;
			s.erase(x);
		}
		else
		{
			cout<<"error cmd!"<<endl;
		}
	}
	
	
	return 0;
}
