-------------------------
Find the Duplicate Number
-------------------------

Given an array arr[] containing n + 1 integers where each integer is between 1 and n (inclusive).
There is only one duplicate element, find the duplicate element in O(n) time complexity and O(1) space.
Examples : 
 

Input  : arr[] = {1, 4, 3, 4, 2} 
Output : 4

Input  : arr[] = {1, 3, 2, 1}
Output : 1

----------------------------------
Approach 1: Sorting
----------------------------------

Intuition

If the numbers are sorted, then any duplicate numbers will be adjacent in the sorted array.

Algorithm

Given the intuition, the algorithm follows fairly simply. First, we sort the array,
and then we compare each element to the previous element. Because there is exactly one duplicated element in the array, 
we know that the array is of at least length 2, and we can return the duplicate element as soon as we find it.

class Solution {
public:
    int findDuplicate(vector<int>& v) {
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==v[i+1])
            {
                return v[i];
            }
        }
        return -1;
        
    }
};
Complexity Analysis

Time complexity : (nlgn)O(nlgn)

The sort invocation costs)O(nlgn) time in Python and Java, so it dominates the subsequent linear scan.

Space complexity : \mathcal{O}(1)O(1) (or O(n))



---------------
Best approach
---------------
ex [1 3 4 2 2]

class Solution {
public:
    int findDuplicate(vector<int>& v) {
 
        for(int i=0;i<v.size();i++)
        {
            // if we get ex [1 3 4 2 2] for 1 st elemnt 1 we get v[1]=4 if positive make it negative
            //so when traversing second another no in forward direction
            //time it will tell the reference of presence.
            
            if(v[abs(v[i])] >0)
            {
                v[abs(v[i])]= -v[abs(v[i])];
            }
            else
            {
                return abs(v[i]); // the no which is negative is repeated.
            }
        }
        return -1;
    }
};


time complexity 
O(n)
space complexity
O(1)

Here a case comes where 0 is also there then add one to all elements of array. 

https://www.youtube.com/watch?v=HuZJqRDOPo0&ab_channel=GeeksforGeeks



---------------------------
 Hare and tortoise approach
 --------------------------
Input  : arr[] = {1, 4, 3, 4, 2} 
Output : 4

Input  : arr[] = {1, 3, 2, 1}
Output : 1
 // CPP code to find the repeated elements
// in the array where every other is present once
#include <iostream>
using namespace std;

// Function to find duplicate
int findDuplicate(int arr[])
{
	// Find the intersection point of
	// the slow and fast.
	int slow = arr[0];
	int fast = arr[0];
	do
	{
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while (slow != fast);

	// Find the "entrance" to the cycle.
	int ptr1 = arr[0];
	int ptr2 = fast;
	while (ptr1 != ptr2)
	{
		ptr1 = arr[ptr1];
		ptr2 = arr[ptr2];
	}

	return ptr1;
}

// Driver code
int main()
{
	int arr[] = { 1, 3, 2, 1 };
	
	cout << findDuplicate(arr) << endl;
	
	return 0;
}

