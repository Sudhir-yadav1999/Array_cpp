-----------------------------------------------
Find the Rotation Count in Rotated Sorted array
-----------------------------------------------

Consider an array of distinct numbers sorted in increasing order.
The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.
Examples: 
Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15, 18}. We get the given array after 
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0
========================================================
#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

int rot_count(int arr[],int low,int high)
{
   
   if(low>high)
   {
       return 0;
   }
   if(high == low)
    {
       return low; 
    }
    
    int mid=(high+low)/2;
    
    if(mid<high && arr[mid+1]<arr[mid])
    {
     return mid+1; 
    }
    
    if(mid>low && arr[mid]<arr[mid-1])
    {
        return mid;
    }
    
    if(arr[low]>arr[mid])
    {
     return rot_count(arr,mid+1,high);  
    }
    return rot_count(arr,low,mid-1);
    
}

int main()
{
 
   int arr[]={15, 18, 2, 3, 6, 12};
   int size=sizeof(arr)/sizeof(arr[0]);
  
   cout<<"Rotation count in an sorted and rotated array :"<<rot_count(arr,0,size-1);


    return 0;
}

========================================================
#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

int rot_count(int arr[],int n)
{
   
   int i,min=arr[0];
   int index;
   for(i=0;i<n;i++)
   {
   
   if(arr[i]<min)
    {
        min=arr[i];
        index=i;
    }   
   }
   
   return index;
   
    
}

int main()
{
 
   int arr[]={15, 18, 2, 3, 6, 12};
   int size=sizeof(arr)/sizeof(arr[0]);
  
   cout<<"Rotation count in an sorted and rotated array :"<<rot_count(arr,size);


    return 0;
}
=================================================================================
  
