------------------------------------------------
Find whether an array is subset of another array
------------------------------------------------
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.

Examples: 

Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1} 
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4} 
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3} 
Output: arr2[] is not a subset of arr1[] 

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>

/* Return 1 if arr2[] is a subset of
arr1[] */
bool isSubset(int arr1[], int arr2[],
			int m, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr2[i] == arr1[j])
				break;
		}

		/* If the above inner loop was
		not broken at all then arr2[i]
		is not present in arr1[] */
		if (j == m)
			return 0;
	}

	/* If we reach here then all
	elements of arr2[] are present
	in arr1[] */
	return 1;
}

// Driver code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[]");

	getchar();
	return 0;
}
Time Complexity: O(m*n)
  
 Method 2 (Use Sorting and Merging ) 

Sort both arrays: arr1[] and arr2[] which takes O(mLogm + nLogn)
Use Merge type of process to see if all elements of sorted arr2[] are present in sorted arr1[].
  // C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;

/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[],
			int m, int n)
{
	int i = 0, j = 0;

	if (m < n)
		return 0;

	// Sort both the arrays
	sort(arr1, arr1 + m);
	sort(arr2, arr2 + n);

	// Iterate till they donot exceed their sizes
	while (i < n && j < m)
	{
		// If the element is smaller than
		// Move aheaad in the first array
		if (arr1[j] < arr2[i])
			j++;
		// If both are equal, then move
		// both of them forward
		else if (arr1[j] == arr2[i])
		{
			j++;
			i++;
		}

		// If we donot have a element smaller
		// or equal to the second array then break
		else if (arr1[j] > arr2[i])
			return 0;
	}

	return (i < n) ? false : true;
}

// Driver Code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, arr2, m, n))
		printf("arr2[] is subset of arr1[] ");
	else
		printf("arr2[] is not a subset of arr1[] ");

	return 0;
}

Time Complexity: O(mLogm + nLogn) which is better than method 2. 
Please note that this will be the complexity if an nLogn algorithm is used for sorting both arrays which is not the case in above code. 
In above code Quick Sort is used and worst case time complexity of Quick Sort is O(n^2)
    
    
 Method 3 (Use Hashing)  

Create a Hash Table for all the elements of arr1[].
Traverse arr2[] and search for each element of arr2[] in the Hash Table. If element is not found then return 0.
If all elements are found then return 1.
  
// C++ code to find whether an array is subset of
// another array
#include <bits/stdc++.h>
using namespace std;

/* Return true if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int m,
			int arr2[], int n)
{

	// Using STL set for hashing
	set<int> hashset;

	// hset stores all the values of arr1
	for (int i = 0; i < m; i++)
	{
		hashset.insert(arr1[i]);
	}

	// loop to check if all elements of arr2 also
	// lies in arr1
	for (int i = 0; i < n; i++) {
		if (hashset.find(arr2[i]) == hashset.end())
			return false;
	}
	return true;
}

// Driver Code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, m, arr2, n))
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
			<< "\n";
	return 0;
}

  Method 4 (Use Set)

Insert into the set for the first array; that’s how we will know the elements in the array.
Save the size of the array after inserting the first array element.
Insert into the same set for the second array.
Check if the size of the set is still the same or not, if it is then it’s true else false.
 Below is the implementation of the above approach: 


#include <bits/stdc++.h>
using namespace std;

int main()
{
	// code
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);
	unordered_set<int> s;
	for (int i = 0; i < m; i++) {
		s.insert(arr1[i]);
	}
	int p = s.size();
	for (int i = 0; i < n; i++) {
		s.insert(arr2[i]);
	}
	if (s.size() == p) {
	cout << "arr2[] is subset of arr1[] "
			<< "\n";
	}
	else {
		cout << "arr2[] is not subset of arr1[] "
			<< "\n";
	}
	return 0;
}
Method 5 (Use Frequency Table)  

Create a Frequency Table for all the elements of arr1[].
Traverse arr2[] and search for each element of arr2[] in the Frequency Table. if element is found decrease the frequency, If element frequency is not found then return 0.
If all elements are found then return 1.
  // C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;
/* Return true if arr2[] is a subset of arr1[] */

bool isSubset(int arr1[], int m,
			int arr2[], int n)
{
	// Create a Frequency Table using STL
	map<int, int> frequency;
	
	// Increase the frequency of each element
	// in the frequency table.
	for (int i = 0; i < m; i++)
	{
		frequency[arr1[i]]++;
	}
	// Decrease the frequency if the
	// element was found in the frequency
	// table with the frequency more than 0.
	// else return 0 and if loop is
	// completed return 1.
	for (int i = 0; i < n; i++)
	{
		if (frequency[arr2[i]] > 0)
			frequency[arr2[i]]--;
		else
		{
			return false;
		}
	}
	return true;
}

// Driver Code
int main()
{
	int arr1[] = { 11, 1, 13, 21, 3, 7 };
	int arr2[] = { 11, 3, 7, 1 };
	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	if (isSubset(arr1, m, arr2, n))
		cout << "arr2[] is subset of arr1[] "
			<< "\n";
	else
		cout << "arr2[] is not a subset of arr1[] "
			<< "\n";
	return 0;
}
Time Complexity: O(m+n) which is better than method 1,2,3

