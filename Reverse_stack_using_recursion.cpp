#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int>s;


void insert(int p)
{
	if(s.size()==0)
		s.push(p);
	
	else
	{
		int c=s.top();
		s.pop();
		insert(p);
		s.push(c);
	}
}


void reverse(int ch)
{
	if(s.size()==0)
		return;

	int p=s.top();
	s.pop();
	reverse(p);
	insert(p);
}

int main()
{
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverse(s.top());

	for(int i=0;i<4;i++)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}