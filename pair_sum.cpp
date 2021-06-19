--------------------------------------------------------------------------
Given a sorted and rotated array, find if there is a pair with a given sum
---------------------------------------------------------------------------

Given an array that is sorted and then rotated around an unknown point.
Find if the array has a pair with a given sum ‘x’. 
It may be assumed that all elements in the array are distinct.

Examples : 

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.


#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;
int pairsum(int arr[],int n,int sum)
{
    
    int i;
    for(i=0;i<n;i++)
    {
     if(arr[i+1]<arr[i])
     {
         break;
     }
        
    }
    int smaller=(i+1)%n; //mod is used go check that next element is not the end of array ,to continue program if its so to adjust it to starting of array again
    int larger=i;
    
    
    while(larger!=smaller)
    {
        if(arr[larger]+arr[smaller]== sum)
        {
            cout<<"Pair are : ("<<arr[smaller]<<","<<arr[larger]<<")"<<endl;
            return sum;
        }
        
        if(arr[larger]+arr[smaller] < sum)
        {
            smaller=(smaller+1)%n;
        }
        else
        {
            larger=(n+larger-1)%n; 
        }
        
        
        
    }
    
    return -1;
    
}

int main()
{
   int sum=16;
   int arr[]={11,15,6,8,9,10};
   int size=sizeof(arr)/sizeof(arr[0]);
   cout<<"The pair sum of the sorted and rotated array"<<" sum is "<<sum<<endl;

   int val=pairsum(arr,size,sum);

    if(val!=-1)
    {
        cout<<"Two values are there with pair sum ::"<<sum<<endl;
    }
    else
    {
        cout<<"Pair sum is not present in the array ::"<<endl;
    }


    return 0;
}
------------------------------------------------------------------------------------------------------
