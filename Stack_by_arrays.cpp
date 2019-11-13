#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int size=5;
int arr[size],top=-1;

bool isFull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
}

bool isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void push()
{
	if(isFull())
		cout<<"Stack is Full"<<endl;
	else
	{
		cout<<"Enter the element"<<endl;
		int n;
		cin>>n;
		top++;
		arr[top]=n;
		cout<<n<<" is pushed into stack"<<endl;
	}
}

void pop()
{
	if(isEmpty())
		cout<<"Stack is empty"<<endl;
	else
	{
		cout<<arr[top]<<" is the popped element"<<endl;
		arr[top]=0;
		top--;
	}
}

void peek()
{
	if(isEmpty())
		cout<<"Stack is empty"<<endl;
	else
		cout<<arr[top]<<" is the peeked element"<<endl;
}

int main()
{
	int ch;
	while(1)
	{
		cout<<"Enter Your choice"<<endl;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Peek"<<endl;
		cout<<"4.Quit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
			    exit(0);
			default:
				cout<<"Enter a valid option"<<endl;
				break;
		}
	}
}