Largest Sum Contiguous Subarray
--------------------------------
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
kadane-algorithm

-------------------
Kadane’s Algorithm:
-------------------
Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far
-----------------------------------------------
#include <iostream>

#include <bits/stdc++.h>

using namespace std; 
void largestarray(int arr[],int n)
{
	
	int max_till=0;
	int element_traverse=0;
	//algo says that start from zero to all element but is got negative make sum =0; 
	//then allow it to calculate sum after the negative value.
	for(int i=0;i<n;i++)
	{
		element_traverse=element_traverse+arr[i];
		if(element_traverse< 0)
		{
			element_traverse=0;
			
		}
		else if(max_till<element_traverse)
		{
			max_till=element_traverse;
		}
	}
	cout<<"Max Array sum"<<max_till;
	
	
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
