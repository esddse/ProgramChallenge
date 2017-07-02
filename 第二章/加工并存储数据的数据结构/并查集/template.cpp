#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

/*
���鼯ģ�� 
*/

#define MAX_N 1000

int parent[MAX_N]; // ���ڵ� 
int rank[MAX_N];   // ���߶� 


// ��ʼ��n��Ԫ�� 
void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

// ��ѯx�ĸ� 
int find(int x)
{
	if(parent[x] == x)
		return x;
	else 
		return parent[x] = find(parent[x]);	
}

// �ϲ�x��y�ļ���
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
			rank[x] ++�� 
	}	
} 

// �ж�x��y�Ƿ�����ͬһ������ 
bool same(int x, int y)
{
	return find(x) == find(y);
}

