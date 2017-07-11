#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>

using namespace std;

set<string> s[30];

void print(int depth)
{
	while(!s[depth].empty())
	{
		int d = depth;
		while(d--) cout<<"|     ";
		cout<<*s[depth].begin()<<endl;
		s[depth].erase(s[depth].begin());
	}	
}

int main()
{
	//freopen("input", "r", stdin);
	
	string input;
	int dataset_num = 1, depth = 0;
	bool comp = true;
	
	while(cin>>input)
	{
		if(input == "#") break;
		if(comp) {
			cout<<"DATA SET "<<dataset_num<<":"<<endl;
			cout<<"ROOT"<<endl;
			comp = false;
		}
		if(input == "*"){
			print(depth); cout<<endl;
			for(int i = 0; i < 30; i++) s[i].clear();
			dataset_num ++;
			comp = true;
		}else if(input[0] == 'd'){
			depth++;
			for(int i = 0; i < depth; i++) cout<<"|     ";
			cout<<input<<endl;
		}else if(input == "]"){
			print(depth--);
		}
		else if(input[0] == 'f'){
			s[depth].insert(input);
		}	
	} 
	
	return 0;
 } 
