#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define N 9
  
bool arr[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 
  
bool knows(int a, int b) 
{ 
    return arr[a][b]; 
} 
  

int celebrity(int n) 
{ 
   
    stack<int> s; 
  
    int cele;
  
    for(int i=0;i<n;i++) 
        s.push(i); 
  
    int A=s.top(); 
    s.pop(); 
    int B=s.top(); 
    s.pop(); 
  
    while(s.size()>1) 
    { 
        if(knows(A,B)) 
        { 
            A=s.top(); 
            s.pop(); 
        } 
        else
        { 
            B=s.top(); 
            s.pop(); 
        } 
    } 
 
    cele=s.top(); 
    s.pop(); 
  
    if(knows(cele,B)) 
        cele=B; 
  
    if(knows(cele,A)) 
        cele=A; 
  
 
    for(int i=0;i<n;i++) 
    { 
        if((i!=cele)&&(knows(cele,i)||!knows(i,cele))) 
            return -1; 
    } 
  
    return cele; 
} 
  
int main() 
{ 
    int n=4; 
    int id=celebrity(n); 
    id==-1?cout<<"No celebrity":cout << "Celebrity ID "<<id; 
    return 0; 
} 