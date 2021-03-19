------------------------------------------
Largest sum contiguous increasing subarray
------------------------------------------
Given an array of n positive distinct integers. 
The problem is to find the largest sum of contiguous increasing subarray in O(n) time complexity.
-------------------------------------------------------------------------------------------------
Examples :
----------
Input : arr[] = {2, 1, 4, 7, 3, 6}
Output : 12
Contiguous Increasing subarray {1, 4, 7} = 12

Input : arr[] = {38, 7, 8, 10, 12}
Output : 38
---------------------------------------------

#include <iostream>

#include <bits/stdc++.h>

using namespace std; 
void largestarray(int arr[],int n)
{
	int result=0;
	
	for(int i=0;i<n;i++)
	{ 
		
		
		int count=arr[i];
		
		while(i+1<n && arr[i+1]>arr[i])
		{
			count=count +arr[i+1];
			i++;
		}
		if(count >result)
		{
			result=count;
		}
		
		
		
		
	}
	cout<<"THe longst array sequence largest sum is"<<result;
	
}
int main() 
{ 
 
 int arr[10];
 int n;
 
 cout<<"Enter the size of the array"<<endl;
 cin>>n;
 cout<<"Enter the array ";
 
 for(int i=0;i<n;i++)
 {
 	cin>>arr[i];
 }

   largestarray(arr,n);
  
  
    return 0; 
    
} 
