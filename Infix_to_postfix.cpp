#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

int prec(char c) 
{ 
	if(c == '^') 
	return 3; 
	else if(c == '*' || c == '/') 
	return 2; 
	else if(c == '+' || c == '-') 
	return 1; 
	else
	return -1; 
} 

void in_to_pos(string str)
{
	stack<char> ch;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			cout<<str[i];
		else if(str[i]=='(')
			ch.push(str[i]);
		else if(str[i]==')')
		{
			while(!ch.empty()&&ch.top()!='(')
			{
				cout<<ch.top();
				ch.pop();
			}
			ch.pop();
		}
		else
		{
				if(prec(str[i])<=prec(ch.top()))
			    {
					while(!ch.empty()&&prec(str[i])<=prec(ch.top()))
					{
						cout<<ch.top();
						ch.pop();
					}
			    }
			    ch.push(str[i]);
		}
	
	}
	while(!ch.empty())
	{
		cout<<ch.top();
		ch.pop();
	}
}

int main()
{
	string s;
	cin>>s;
	in_to_pos(s);
}