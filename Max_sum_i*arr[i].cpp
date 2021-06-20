
-------------------------------------------------------------------------------
Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
-------------------------------------------------------------------------------

Remember :  currval = currval+add_sum-n*arr[n-j]; 



Input: arr[] = {1, 20, 2, 10}
Output: 72
We can get 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}
Output: 330
We can get 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330
==========================================================  
Let us calculate initial value of i*arr[i] with no rotation
R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]

After 1 rotation arr[n-1], becomes first element of array, 
arr[0] becomes second element, arr[1] becomes third element
and so on.
R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]

R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]

After 2 rotations arr[n-2], becomes first element of array, 
arr[n-1] becomes second element, arr[0] becomes third element
and so on.
R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n-1)*arr[n-3]

R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]

If we take a closer look at above values, we can observe 
below pattern

Rj - Rj-1 = arrSum - n * arr[n-j]

Where arrSum is sum of all array elements, i.e., 

arrSum = ∑ arr[i]
        0<=i<=n-1
=================================================================
Below is complete algorithm: 
=================================================================
1) Compute sum of all array elements. Let this sum be 'arrSum'.

2) Compute R0 by doing i*arr[i] for given array. 
   Let this value be currVal.

3) Initialize result: maxVal = currVal // maxVal is result.

// This loop computes Rj from  Rj-1 
4) Do following for j = 1 to n-1
......a) currVal = currVal + arrSum-n*arr[n-j];
......b) If (currVal > maxVal)
            maxVal = currVal   

5) Return maxVal
==================================================================
#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

int max_sum(int arr[],int n)
{
    int currval = 0;
    int add_sum = 0;
    
    for(int i=0;i<n;i++)
    {
       add_sum = add_sum+arr[i];// sum of array element 
       
       currval = currval+i*arr[i];// sum of arr[i] * i 
        
    }
    
    int max=currval;
    
    // rotating on the basis of rotation ie n-1 if size is n then n-1 rotation will be there 
    for(int j=1;j<n;j++)
    {
        currval = currval+add_sum-n*arr[n-j]; // arr[n-j] here n is size of array and j is no of rotation
         
        if(currval>max)
        {
         max = currval;
            
        }
        
    }
    
    return max;
    
    
}

int main()
{
   int sum=16;
   int arr[]={1, 20, 2, 10};
   int size=sizeof(arr)/sizeof(arr[0]);
  
   cout<<"Max sum of i*arr[i] after rotation ::"<<max_sum(arr,size);


    return 0;
}





=====================================================================
        time complexity - 0(n2)
        
        #include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

int max_sum(int arr[],int n)
{
    int res=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        int curr_sum=0;
        
        for(j=0;j<n;j++)
        {
            int index=(i+j)%n;
            curr_sum=curr_sum+j*arr[index];
        }
        
         res=max(res,curr_sum);
    }
    return res;
    
}

int main()
{
   int sum=16;
   int arr[]={1, 20, 2, 10};
   int size=sizeof(arr)/sizeof(arr[0]);
  
   cout<<"Max sum of i*arr[i] after rotation ::"<<max_sum(arr,size);


    return 0;
}

