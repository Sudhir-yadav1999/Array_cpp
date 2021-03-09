
----------------------
Kth elemnt in a array 
-----------------------
#include<bits/stdc++.h>

using namespace std;

int kth_element(int arr[],int n,int k)
{
	sort(arr,arr+n);
	
	return arr[k-1]; 
	
}

int main()
{
 int n,arr[10],k;
 cout<<"Enter the no of elements in a array:";
 cin>>n;
 
 for(int i=0;i<n;i++)
 {
 	cin>>arr[i];
 	
 }
 cout<<"Enter the no you want to search :";
 cin>>k;
 
 int ele=kth_element(arr,n,k);
 cout<<"The value of the elment : "<<ele;

  
	return 0;
}
Time Complexity: O(Nlog N)
