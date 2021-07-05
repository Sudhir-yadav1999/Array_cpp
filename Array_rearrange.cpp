---------------------------------------
Rearrange an array such that arr[i] = i
---------------------------------------
Given an array of elements of length N, ranging from 0 to N – 1.
All elements may not be present in the array. 
If the element is not present then there will be -1 present in the array.
Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.

Examples: 

Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]

Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
              11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
         11, 12, 13, 14, 15, 16, 17, 18, 19]


#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

int sorti(int arr[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        if(i==arr[j])
        {
        
        int temp=arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
        break;
        }
        
        }
        
        
        
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i)
        {
            arr[i]=-1;
        }
    }
    
    
    
    
    
}

int main()
{
  
    int arr[]={19,7,0,3,18,15,12,6,1,11,10,9,5,13,16,2,14,17,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    sorti(arr,size);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}

Time complexity - 0(n2)


-----------------
hash map solution 
-----------------


#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

int sorti(int arr[],int n)
{
    
  unordered_map<int,int> hash;
  
  // add elements to hashmap
  for(int i=0;i<n;i++)
  {
      if(arr[i]!=-1)
      {
      hash[arr[i]]++;
  }}
  
  for(int i=0;i<n;i++)
  {
      if(hash.find(i) != hash.end())
      {//if element is present 
          
          arr[i]=i;
      }
      else 
      { 
          arr[i]=-1;
      }
  }
  
  
  
}

int main()
{
  
    int arr[]={19,7,0,3,18,15,12,6,1,11,10,9,5,13,16,2,14,17,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    sorti(arr,size);

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}





