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

void push()
{
	cout<<"Enter the element"<<endl;
	Node* temp=new Node();
	cin>>temp->data;
	temp->link=top;
	top=temp;
	cout<<temp->data<<" is pushed into stack"<<endl;
}

void pop()
{
	if(isEmpty())
		cout<<"Stack is empty"<<endl;
	else
	{
		cout<<top->data<<" is the popped element"<<endl;
		Node* temp=top;
		top=top->link;
		delete temp;
	}
}

void peek()
{
	if(isEmpty())
		cout<<"Stack is empty"<<endl;
	else
		cout<<top->data<<" is the peeked element"<<endl;
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