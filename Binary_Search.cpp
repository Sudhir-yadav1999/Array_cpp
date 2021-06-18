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

int main()
{
  
  int arr[]={2,3,4,10,40};
  int size=sizeof(arr)/sizeof(arr[0]);
  int key=3;
  
  int result=binarySearch(arr,0,size-1,key);
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
