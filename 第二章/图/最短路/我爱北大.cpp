#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cmath> 
#include<algorithm>

using namespace std;

#define INF 0xfffffff

int p, q, r;
map<string, int> str_2_index; 
map<int, string> index_2_str;

struct shortest{
	int len;
	int pre;
} stst[40][40];

int print(int index1, int index2)
{
	if(index1 == index2)
	{
		cout<<index_2_str[index1];
		return 0;
	}
	int len = print(index1, stst[index1][index2].pre);
	cout<<"->("<<stst[index1][index2].len - len<<")->"<<index_2_str[index2];
	return stst[index1][index2].len;
}

int main()
{
	//freopen("input", "r", stdin);
	
	cin>>p;
	string name;
	for(int i = 0; i < p; i++)
	{
		cin>>name;
		str_2_index.insert(make_pair(name, i));
		index_2_str.insert(make_pair(i, name));
		for(int j = 0; j < p; j++)
		{
			stst[i][j].len = (i == j) ? 0 : INF;
			stst[i][j].pre = -1;
		}
	}
	
	cin>>q;
	string name1, name2;
	int len, index1, index2;
	while(q--)
	{
		cin>>name1>>name2>>len;
		index1 = str_2_index[name1];
		index2 = str_2_index[name2];
		if(len < stst[index1][index2].len)
		{
			stst[index1][index2].len = stst[index2][index1].len = len;
			stst[index1][index2].pre = index1;
			stst[index2][index1].pre = index2;
		}
	}
	
	// Floyd
	for(int k = 0; k < p; k++)
		for(int i = 0; i < p; i++)
			for(int j = 0; j < p; j++)
				if(stst[i][j].len > stst[i][k].len + stst[k][j].len)
				{
					stst[i][j].len = stst[i][k].len + stst[k][j].len;
					stst[i][j].pre = stst[k][j].pre;
				}
	
	cin>>r;
	while(r--)
	{
		cin>>name1>>name2;
		index1 = str_2_index[name1];
		index2 = str_2_index[name2];

		print(index1, index2);
		cout<<endl;
	}
	
	return 0;
 } 
