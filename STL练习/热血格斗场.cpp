#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<list>

using namespace std;

int n; 
int id, val;

map<long long, int> mp;

int search(int val)
{
	map<long long, int>::iterator iter = mp.upper_bound(val);
	if(iter == mp.end())
		return (--iter)->second;
	else if(iter == mp.begin())
		return iter->second;
	else
	{
		int id1 = iter->second; long long diff1 = abs(iter->first - val);
		iter--;
		int id2 = iter->second; long long diff2 = abs(iter->first - val);
		if(diff1 < diff2)
			return id1;
		else if(diff1 > diff2)
			return id2;
		else
			return iter->first > val ? id1 : id2;
	}
}

int main()
{
	//freopen("input", "r", stdin);
	
	mp[1000000000] = 1;
	
	cin>>n;
	while(n--)
	{
		cin>>id>>val;
		cout<<id<<" "<<search(val)<<endl;
		mp[val] = id; 
	}
	
	return 0;
}
