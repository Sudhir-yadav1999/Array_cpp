
-----------------------------------------------
Merge 2 sorted arrays without using Extra space
-----------------------------------------------

// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to merge two arrays
void merge(int arr1[], int arr2[], int n, int m)
{
	int i = 0, j = 0, k = n - 1;

	// Untill i less than equal to k
	// or j is less tha m
	while (i <= k and j < m) {
		if (arr1[i] < arr2[j])
			i++;
		else {
			swap(arr2[j++], arr1[k--]);
		}
	}

	// Sort first array
	sort(arr1, arr1 + n);

	// Sort second array
	sort(arr2, arr2 + m);
}

// Driver Code
int main()
{

	int ar1[] = { 1, 5, 9, 10, 15, 20 };
	int ar2[] = { 2, 3, 8, 13 };
	int m = sizeof(ar1) / sizeof(ar1[0]);
	int n = sizeof(ar2) / sizeof(ar2[0]);
	merge(ar1, ar2, m, n);

	cout << "After Merging \nFirst Array: ";
	for (int i = 0; i < m; i++)
		cout << ar1[i] << " ";
	cout << "\nSecond Array: ";
	for (int i = 0; i < n; i++)
		cout << ar2[i] << " ";
	return 0;
}

Output

After Merging 
First Array: 1 2 3 5 8 9
Second Array: 10 13 15 20

Complexities:

Time Complexity: The time complexity while traversing the arrays in while loop is O(n+m) in worst case and sorting is O(nlog(n) + mlog(m)).
So overall time complexity of the code becomes O((n+m)log(n+m)).
Space Complexity: As the function doesn’t use any extra array for any operations, the space complexity is O(1).

