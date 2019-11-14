#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

void stock_span(int arr[],int n)
{
	stack<int> s;
	int sum=1;
	int span[n];
	span[0]=1;
	s.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		if(arr[i]<s.top())
				span[i]=1;
		
		else
		{
			while(!s.empty()&&arr[i]>s.top())
			{
				sum++;
				s.pop();
			}
			span[i]=sum;
		}
		s.push(arr[i]);
	}
	
	for(int i=0;i<n;i++)
		cout<<span[i]<<" ";
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	stock_span(arr,n);
}