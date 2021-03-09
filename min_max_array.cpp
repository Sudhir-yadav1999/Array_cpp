-----------------------
Min-Max using Brute Force
-----------------------
#include<bits/stdc++.h>

using namespace std;

int min(int arr[],int n)
{
	int minn=arr[0];
	for(int i=0;i<n;i++)
	{
	  if(arr[i]<minn)
	  {
	  	minn=arr[i];
	  }
	}
	
	return minn;
}

int max(int arr[],int n)
{
	int maxx=0;
	for(int i=0;i<n;i++)
	{
	  if(arr[i]>maxx)
	  {
	  	maxx=arr[i];
	  }
	}
	
	
	return maxx;
}

int main()
{
  int arr[10],n;
  cout<<"Enter the size of the array :";
  cin>>n;
  for(int i=0;i<n;i++)
  {
  	cin>>arr[i];
  }
  
  int mm=min(arr,n);
  int mx=max(arr,n);

  cout<<mm<<endl;
  cout<<mx<<endl;
  
	return 0;
}

Time complexity - O(n)
	
