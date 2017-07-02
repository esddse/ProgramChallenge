#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

/*
并查集模板 
*/

#define MAX_N 1000

int parent[MAX_N]; // 父节点 
int rank[MAX_N];   // 树高度 


// 初始化n个元素 
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

// 查询x的根 
int find(int x)
{
	if(parent[x] == x)
		return x;
	else 
		return parent[x] = find(parent[x]);	
}

// 合并x和y的集合
void unit(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x == y)
		return;
	if(rank[x] < rank[y])
		parent[x] = y;
	else
	{
		parent[y] = x;
		if(rank[x] == rank[y])
			rank[x] ++； 
	}	
} 

// 判断x和y是否属于同一个集合 
bool same(int x, int y)
{
	return find(x) == find(y);
}

