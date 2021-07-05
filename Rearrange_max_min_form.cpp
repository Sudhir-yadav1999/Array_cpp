==================================================
Rearrange an array in maximum minimum form | Set 1
==================================================

#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;
  int arr2[7];
int rearrange_alternate(int arr[],int n)
{
     
    
    int i=0;
    
    int j=n-1;
    
    int flag=0;
    
    while(i<=j)
    {
        arr2[flag]=arr[j];
        
        flag++;
        j--;
        
        arr2[flag]=arr[i];
        
        i++;
        flag++;
    }
    
    for(int j=0;j<n;j++)
    {
        cout<<arr2[j]<<endl;
    } 
   
}

int main()
{
  
    int arr[]={1,2,3,4,5};
  
    int size=sizeof(arr)/sizeof(arr[0]);
    rearrange_alternate(arr,size);

   
    return 0;
}
Time Complexity: O(n) 
Auxiliary Space: O(n) 
