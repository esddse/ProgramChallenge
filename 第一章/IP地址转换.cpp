#include<iostream>

using namespace std;

int a, n, m;

void t()
{
	m = 8;
	while(m--)
		cout<<((a>>m)&1);
}

int main()
{
	char c;
	while(cin>>a)
	{
		if(a<0) break;
		n = 3;
		t();
		while(n--)
			cin>>c>>a, t();
		puts("");
	}
}
