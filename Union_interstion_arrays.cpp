
Given two sorted arrays, find their union and intersection.

Example:

Input : arr1[] = {1, 3, 4, 5, 7}
        arr2[] = {2, 3, 5, 6} 
Output : Union : {1, 2, 3, 4, 5, 6, 7} 
         Intersection : {3, 5}

Input : arr1[] = {2, 5, 6}
        arr2[] = {4, 6, 8, 10} 
Output : Union : {2, 4, 5, 6, 8, 10} 
         Intersection : {6}

-----------------------------
Union of two Different arrays
-----------------------------
#include<iostream>
using namespace std;

void union_arr(int arr1[],int arr2[],int size1,int size2)
{
int i=0,j=0;

  while(i<size1 && j<size2)
  {
  	if(arr1[i]<arr2[j])
  	{
  		cout<<arr1[i++]<<" ";
	}
	else if(arr2[j]<arr1[i])
	{
		cout<<arr2[j++]<<" ";
	}
	else 
	{
		cout<<arr1[i++]<<" ";
		j++;
	}
  }
  
  
  while(i<size1)
  {
  	cout<<arr1[i++]<<" ";
  }
  while(j<size2)
  {
  	cout<<arr2[j++]<<" ";
  }

}

int main()
{
	int arr1[]={1, 3, 4, 5, 7};
	int arr2[]={2, 3, 5, 6};

	int size1=sizeof(arr1)/sizeof(arr1[0]);
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	
	union_arr(arr1,arr2,size1,size2);
	
	
	return 0;
	
}



---------------------------------
  Intersection code of two arrays
---------------------------------
#include<iostream>
using namespace std;

void intersection_arr(int arr1[],int arr2[],int size1,int size2)
{
int i=0,j=0;

  while(i<size1 && j<size2)
  {
  	if(arr1[i]<arr2[j])
  	{
  	   i++;
	}
	else if(arr2[j]<arr1[i])
	{
		j++;
	}
	else 
	{
		cout<<arr1[i++]<<" ";
		j++;
	}
  }
  
  

}

int main()
{
	int arr1[]={1, 3, 4, 5, 7};
	int arr2[]={2, 3, 5, 6};

	int size1=sizeof(arr1)/sizeof(arr1[0]);
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	
	intersection_arr(arr1,arr2,size1,size2);
	
	
	return 0;
	
}
