
-------------------------------------------------
Search an element in a sorted and rotated array
-------------------------------------------------

Approach: 
 

The idea is to find the pivot point, divide the array in two sub-arrays and perform binary search.
The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only element for which next element to it is smaller than it.
Using the above statement and binary search pivot can be found.
After the pivot is found out divide the array in two sub-arrays.
Now the individual sub – arrays are sorted so the element can be searched using Binary Search.
Implementation: 
 

Input arr[] = {3, 4, 5, 1, 2}
Element to Search = 1
  1) Find out pivot point and divide the array in two
      sub-arrays. (pivot = 2) /*Index of 5*/
  2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then
             search in left array
      (b) Else Search in right array
          (1 will go in else as 1 < 0th element(3))
  3) If element is found in selected sub-array then return index
     Else return -1.
-=================================================================
#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;


int binarySearch(int arr[],int start,int end,int key)
{
    
    if(end>=start)
    {
        int mid=(start+end)/2;
        
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            return binarySearch(arr,start,mid-1,key);
        }
        else
        {
            return binarySearch(arr,mid+1,end,key);
        }
        
    }
    return -1;
}

int find_pivot(int arr[],int low,int high)
{
    
    //pivot is element whose next no is less than its current element in array
    if(low>high)
    {return -1;}
    if(low==high)
    {
        return low;
    }
    
    int mid=(low+high)/2;
    
    if(mid<high &&arr[mid]>arr[mid+1]) // pivot is the elemnt itself
    {
     return mid;
     
    }
    if(mid > low &&arr[mid-1]>arr[mid])//pivot is mid-1 
    {
        return mid-1;
    }
    if(arr[low]>arr[mid])
    {
        return find_pivot(arr,low,mid-1);
    }
    return find_pivot(arr,mid+1,high);
    
    
}

int pivotedBinarySearch(int arr[],int start,int end,int key)
{
    int pivot_element=find_pivot(arr,0,end-1);
    
    //if pivot is 
    if(pivot_element==-1)
    {
        return binarySearch(arr,0,end-1,key);
    }
    
    if(arr[pivot_element]==key)
    {
        return pivot_element;
    }
    
    if(arr[0]<=key)
    {
        return binarySearch(arr,start,pivot_element-1,key);
    }
    return binarySearch(arr,pivot_element+1,end-1,key);
}

int main()
{
  
  int arr[]={ 5, 6, 7, 8, 9, 10, 1, 2, 3};
  int size=sizeof(arr)/sizeof(arr[0]);
  int key=3;
  
  int result=pivotedBinarySearch(arr,0,size,key);
  
  if(result!=-1)
  {
      cout<<"Key found at index ::"<<result<<endl;
  }
  else
  {
      cout<<"Key not found :"<<endl;
  }
  
    return 0;
}
