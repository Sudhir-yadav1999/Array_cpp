Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array.
The functions should put all 0s first, then all 1s and all 2s in last.
  
Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
-----------------
Sort an array of 0s-1s-and-2s
-----------------
#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void order_reorder(int arr[],int size)
{
	int mid=0;
	int high=size-1;
	int low=0;
	
	//condition incrementing mid till mid <=high
	while(mid<=high)
	{
		switch(arr[mid])
		{
			case 0:
        //swap low and mid to keep all zeros to left of mid and 2 to right of mid
				swap(&arr[low],&arr[mid]);
				mid++;
				low++; //bcz to swap that value of low
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(&arr[mid],&arr[high]);
				high--;//decrement high bcz value on high will be set and dec value will be swapped till mid==high
				break;
		}
		
	}
}
int main()
{
	int arr[]={0,1,2,0,0,1,1,2,2,1,0};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	order_reorder(arr,size);
	
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
		
	}
	
	return 0;
	
}




----------------
Another Approach
----------------

Approach: Count the number of 0s, 1s and 2s in the given array. Then store all the 0s in the beginning followed by all the 1s then all the 2s.
  
Algorithm:

Keep three counter c0 to count 0s, c1 to count 1s and c2 to count 2s
Traverse through the array and increase the count of c0 is the element is 0,increase the count of c1 is the element is 1 and increase the count of c2 is the element is 2
Now again traverse the array and replace first c0 elements with 0, next c1 elements with 1 and next c2 elements with 2.


// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to print the contents of an array 
void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Function to sort the array of 0s, 1s and 2s 
void sortArr(int arr[], int n) 
{ 
	int i, cnt0 = 0, cnt1 = 0, cnt2 = 0; 

	// Count the number of 0s, 1s and 2s in the array 
	for (i = 0; i < n; i++) { 
		switch (arr[i]) { 
		case 0: 
			cnt0++; 
			break; 
		case 1: 
			cnt1++; 
			break; 
		case 2: 
			cnt2++; 
			break; 
		} 
	} 

	// Update the array 
	i = 0; 

	// Store all the 0s in the beginning 
	while (cnt0 > 0) { 
		arr[i++] = 0; 
		cnt0--; 
	} 

	// Then all the 1s 
	while (cnt1 > 0) { 
		arr[i++] = 1; 
		cnt1--; 
	} 

	// Finally all the 2s 
	while (cnt2 > 0) { 
		arr[i++] = 2; 
		cnt2--; 
	} 

	// Print the sorted array 
	printArr(arr, n); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
	int n = sizeof(arr) / sizeof(int); 

	sortArr(arr, n); 

	return 0; 
} 
