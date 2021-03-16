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
