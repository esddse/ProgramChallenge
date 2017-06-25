#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<list>
#include<set>
#include<map>

using namespace std;

int n;

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>n;
	map<int, list<int> > lists;
	
	while(n--)
	{
		string cmd;
		cin>>cmd;
		if(cmd == "new")
		{
			int id;
			cin>>id;
			lists[id] = *(new list<int>);
		}
		else if(cmd == "add")
		{
			int id, num;
			cin>>id>>num;
			lists[id].push_back(num);
		}
		else if(cmd == "out")
		{
			int id;
			cin>>id;
			lists[id].sort();
			for(list<int>::iterator it = lists[id].begin(); it != lists[id].end(); it++)
				cout<<*it<<" ";
			cout<<endl;
		}
		else if(cmd == "merge")
		{
			int id1, id2;
			cin>>id1>>id2;
			lists[id1].merge(lists[id2]);
		} 
		else if(cmd == "unique")
		{
			int id;
			cin>>id;
			lists[id].sort();
			lists[id].unique();
		}
		else 
			cout<<"cmd error!"<<endl;
	}
	
	return 0;
 } 
