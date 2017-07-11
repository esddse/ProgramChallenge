#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int main()
{
	stack<char> st;
	char s[505];
	gets(s);
	
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == ' '){
			if(st.empty()) cout<<' ';
			else{
				while(!st.empty()) cout<<st.top(), st.pop();
				cout<<' ';
			}
		}
		else st.push(s[i]);
	}
	while(!st.empty()) cout<<st.top(), st.pop();
	
	return 0;
}
