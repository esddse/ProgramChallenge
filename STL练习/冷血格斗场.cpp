#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>

using namespace std;

int n;
map<long long, set<int> > mp;
typedef map<long long, set<int> >::iterator map_iter;
map_iter iter, iter2;
typedef pair<map_iter, map_iter> iter_p;
iter_p iter_pair;

int find_min(set<int> s)
{
	return *(s.begin());
}

int search(int val, int id)
{
	int ret_id;
	
	iter = mp.find(val);
	if(iter == mp.end())
	{
		iter = mp.upper_bound(val);
		if(iter == mp.end())
			ret_id = find_min(mp.rbegin()->second);
		else if(iter == mp.begin())	
			ret_id = find_min(mp.begin()->second);
		else
		{
			iter2 = iter;
			long long diff1 = abs((--iter)->first - val);
			long long diff2 = abs(iter2->first - val);
			if(diff1 < diff2)
				ret_id = find_min(iter->second);
			else if(diff1 > diff2)
				ret_id = find_min(iter2->second);
			else 
				ret_id = min(find_min(iter->second), find_min(iter2->second));
		}
		set<int> *s = new set<int>;
		s->insert(id);
		mp[val] = *s;	
	}
	else
	{
		ret_id = find_min(iter->second);
		iter->second.insert(id);
	}
			
	return ret_id;
}

int main()
{
	//freopen("input", "r", stdin);
	
	set<int> s;
	s.insert(1);
	mp[1000000000] = s;
	
	cin>>n;
	while(n--)
	{
		int id, val;
		cin>>id>>val;	
		cout<<id<<" "<<search(val, id)<<endl;
	} 
	
	return 0;
 } 
