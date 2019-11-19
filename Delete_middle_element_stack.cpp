#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int>s;

void middle(int n)
{
	if(s.size()==0)
		return;

	int c=s.top();
	s.pop();
	middle(n-1);
	if(n!=0)
	{
		s.push(c);
	}
}

int main()
{
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	int n=s.size()/2;
	middle(n);

	for(int i=0;i<2*n;i++)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}