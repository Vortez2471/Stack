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
	string ans;
	stack<char> s;
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
		if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z'))
			ans=ans+str[i];
		else if(str[i]=='(')
			s.push(str[i]);
		else if(str[i]==')')
		{
			while(!s.empty()&&s.top()!='(')
			{
				ans=ans+s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			if(prec(str[i])<=prec(s.top()))
			{
				while(!s.empty()&&prec(str[i])<=prec(s.top()))
				{
					ans=ans+s.top();
					s.pop();
				}
			}
			s.push(str[i]);
		}
	}
	while(!s.empty())
	{
		ans+=s.top();
		s.pop();
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;

}


int main()
{
	string str;
	cin>>str;
	in_to_pre(str);
}
