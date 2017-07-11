#include<iostream>
#include<cstdio> 
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int d;
double rate[370];
double c[370][2];

double cut(double f)
{
	return ((double)(int)(f*100))/100;
}

int main()
{
	//freopen("input", "r", stdin);
	
	while(cin>>d)
	{
		if(d == 0) break;
		
		c[0][0] = 1000.0; 
		c[0][1] = 0.0;
		
		for(int i = 1; i <= d; i++)
		{	
			cin>>rate[i];
			c[i][0] = c[i][1] = 0;
			
			c[i][0] = max(c[i-1][0], cut(c[i-1][1] * rate[i] * 0.97)); 
			c[i][1] = max(c[i-1][1], cut(c[i-1][0] / rate[i] * 0.97)); 
		}	
		printf("%.2lf\n", c[d][0]);
	}
	
	return 0;
} 
