Program to cyclically rotate an array by one

Given an array, cyclically rotate the array clockwise by one


Input:  arr[] = {1, 2, 3, 4, 5}
Output: arr[] = {5, 1, 2, 3, 4}
-------------------------------
Rotate an array by one position
-------------------------------
#include<iostream>
using namespace std;

void arr_rot(int arr1[],int size1, int rot)
{
	int i;
		for(int j=0;j<rot;j++)
		{
			int temp=arr1[size1];
			for(i=size1-rot;i>=0;i--)
	        {
		    arr1[i+1]= arr1[i];
		     
	        } 
	        arr1[++i]=temp;
	        
		}
		for(int i=0;i<=size1;i++)
		{
			cout<<arr1[i]<<" ";
		}
	
}

int main()
{
	int arr1[]={1, 3, 4, 5, 7};
	

	int size1=sizeof(arr1)/sizeof(arr1[0]);
	int rot;
	cout<<"Enter the no of rotation you want to perform ";

	arr_rot(arr1,size1-1,1);
	
	
	return 0;
	
}


-------------------------------------
User input no of times array rotation
-------------------------------------
#include<iostream>
using namespace std;

void arr_rot(int arr1[],int size1, int rot)
{
	    int i;
	    
		for(int j=0;j<rot;j++)
		{
			int temp=arr1[size1];
			
			for(i=size1-1;i>=0;i--)
	        {
		    arr1[i+1]= arr1[i];
		     
	        } 
	        arr1[++i]=temp;
	        
		}
		for(int i=0;i<=size1;i++)
		{
			cout<<arr1[i]<<" ";
		}
	
}

int main()
{
	int arr1[]={1, 3, 4, 5, 7};
	

	int size1=sizeof(arr1)/sizeof(arr1[0]);
	int rot;
	cout<<"Enter the no of rotation you want to perform ";
    	cin>>rot;
	arr_rot(arr1,size1-1,rot);
	
	
	return 0;
	
}
----------------------------------------------------------------------------------

 =========================	
|Array Rotation Algorithm |
 =========================


Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1].
The idea of the algorithm is : 

Reverse A to get ArB, where Ar is reverse of A.
Reverse B to get ArBr, where Br is reverse of B.
Reverse all to get (ArBr) r = BA.
	
Example : 
Let the array be arr[] = [1, 2, 3, 4, 5, 6, 7], d =2 and n = 7 
A = [1, 2] and B = [3, 4, 5, 6, 7] 
 
Reverse A, we get ArB = [2, 1, 3, 4, 5, 6, 7]
Reverse B, we get ArBr = [2, 1, 7, 6, 5, 4, 3]
Reverse all, we get (ArBr)r = [3, 4, 5, 6, 7, 1, 2]
	
	
#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;


void reversal(int arr[],int start,int end)
{
    
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void rotation(int arr[],int n,int d)
{
    if(d==0)
    {
        return ;
    }
    
    //if rotating factor is more than no of elements so :: modulo is used 
    
    d=d%n; //2 mod 7 == 2 ie remainder of 2/7= 2 remainder , qut=0
    
    reversal(arr,0,d-1); // reverse a =[1,2] b=[3,4,5,6,7]  reversal a=[2,1]
    reversal(arr,d,n-1); // reverse b=[2,1,7,6,5,4,3]
    reversal(arr,0,n-1); // reverse whole a wrt b =[3,4,5,6,7,1,2]
}

void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
  
  cout<<"Rotation algorithm ::"<<endl;
  int arr[]={1,2,3,4,5,6,7};
  int size=sizeof(arr)/sizeof(arr[0]);
  
  int d=2;//rotating factor by 2
 
  rotation(arr,size,d);
  
  print(arr,size);
  
  
    return 0;
}

