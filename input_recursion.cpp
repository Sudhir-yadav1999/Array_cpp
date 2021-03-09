------------------------------
Input an array using recursion
------------------------------
#include<bits/stdc++.h>

using namespace std;

//reverse array

void reverse(int arr[],int start,int end)
{

if(start>=end)
{
	return ;
}

int temp=arr[start];
arr[start]=arr[end];
arr[end]=temp;

 reverse(arr,start+1,end-1);//start from value+1 to value -1
	
}

//print array

void print(int arr[],int n)
{
	for(int i=0;i<=n;i++)
	{
		cout<<arr[i]<<" ";
		
	}

  
//input using recusion 
  
void input(int arr[],int n,int i)
{
if(n<0)
{
	return;
}
		
cin>>arr[i];
	
input(arr,n-1,i+1);
	
}
int main()
{
 int n;
 int arr[10];
 cout<<"Enter no of array elements :";
 cin>>n;
  
 int i=0;
  
 input(arr,n-1,i);
 
 reverse(arr,0,n-1);//  start: 0 to end : 5
  
 print(arr,n-1);
	return 0;
}
