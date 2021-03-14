
Move all negative numbers to beginning and positive to end with constant extra space

An array contains both positive and negative numbers in random order. 
Rearrange the array elements so that all negative numbers appear before all positive numbers.
  
Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
--------------------------------------
Positive on right and negative on left
--------------------------------------
#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void arrange_arr(int arr[],int size)
{
	int j=0;
	//j increment when swap occurs so j is always positive and 
	//on getting value negative by arr[i] it swaps with positive value of j
	for(int i=0;i<size-1;i++)
	{
		if(arr[i]<0 )
		{ 
		if(i!=j)
		{
			swap(&arr[j],&arr[i]);
		}
		
		j++;
			
		}
		
	}
	
	

}

int main()
{
	int arr[]={-1, 2, -3, 4, 5, 6, -7, 8, 9};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	arrange_arr(arr,size);
	
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
		
	}
	
	return 0;
	
}

---------------------
Two pointer approach
---------------------

#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void arrange_arr(int arr[],int size,int left,int right )
{

while(left<=right)
{
  // left is negative and right is poisitve
	if(arr[left]<0 && arr[right]>0)
	{
		left+=1;
		
	}
  //left is positive and right is negative
	else if(arr[left]>0 && arr[right]<0)
	{
		swap(&arr[left],&arr[right]);
		left+=1;
		right-=1;
	}
  //left is positive and right is positive
	else if(arr[left]>0 &&arr[right]>0)
	{
		right-=1;
	}
  //all the other case 
	else
	{
		left+=1;
		right-=1;
		
	}
}
	

}

int main()
{
	int arr[]={-1, 2, -3, 4, 5, 6, -7, 8, 9};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	arrange_arr(arr,size,0,size-1);
	
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
		
	}
	
	return 0;
	
}
