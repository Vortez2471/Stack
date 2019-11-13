#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* link;
};

Node* top=NULL;

bool isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void push(int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->link=top;
	top=temp;
}

void pop()
{
	if(isEmpty())
		cout<<"Stack is empty"<<endl;
	else
	{
		Node* temp=top;
		top=top->link;
		delete temp;
	}
}

void next_greater(int arr[],int n)
{
	push(arr[0]);
	for(int i=1;i<n;i++)
	{
		if(arr[i]>top->data)
		{
			while(!isEmpty())
			{
				cout<<top->data<<"->"<<arr[i]<<endl;
				pop();
			}
			push(arr[i]);
		}
		else
		{
			push(arr[i]);
		}
	}
	while(!isEmpty())
	{
		cout<<top->data<<"->"<<-1<<endl;
		pop();
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	next_greater(arr,n);
}