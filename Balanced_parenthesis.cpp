#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void parenthesis(string str)
{
	stack<char>s;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='('||str[i]=='{'||str[i]=='[')
			s.push(str[i]);
		else if(str[i]==')')
		{
			while(!s.empty()&&s.top()!='(')
			{
				s.pop();
			}
			s.pop();
		}
		else if(str[i]=='}')
		{
			while(!s.empty()&&s.top()!='{')
			{
				s.pop();
			}
			s.pop();
		}
		else if(str[i]==']')
		{
			while(!s.empty()&&s.top()!='[')
			{
				s.pop();
			}
			s.pop();
		}
	}
	if(s.empty())
		cout<<"Balanced"<<endl;
	else
		cout<<"Not Balanced"<<endl;
}

int main()
{
	string s;
	cin>>s;
	parenthesis(s);
}