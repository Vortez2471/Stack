#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

int prec(char a)
{
	if(a=='+'||a=='-')
		return 1;
	if(a=='*'||a=='/')
		return 2;
	if(a=='^')
		return 3;
	else
		return -1;
}



void in_to_pre(string str)
{
	stack<char> ch;
	string ans;
	reverse(str.begin(),str.end());
	for (int i = 0; i < str.size(); i++) 
	{ 
  
        if (str[i] == '(') 
        { 
            str[i] = ')'; 
            i++; 
        } 
        else if (str[i] == ')') 
        { 
            str[i] = '('; 
            i++; 
        } 
    } 
	for(int i=0;i<str.size();i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			ans=ans+str[i];
		else if(str[i]=='(')
			ch.push(str[i]);
		else if(str[i]==')')
		{
			while(!ch.empty()&&ch.top()!='(')
			{
				ans=ans+ch.top();
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
						ans=ans+ch.top();
						ch.pop();
					}
			    }
			    ch.push(str[i]);
		}
	
	}
	while(!ch.empty())
	{
		ans=ans+ch.top();
		ch.pop();
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}



int main()
{
	string str;
	cin>>str;
	in_to_pre(str);
}
