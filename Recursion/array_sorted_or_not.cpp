// C++ Recursive approach to check if an
// Array is sorted or not
#include <iostream>
using namespace std;

// Function that returns true if array is
// sorted in non-decreasing order.
bool arraySortedOrNot(int a[], int n)
{
	
	// Base case
	if (n == 1 || n == 0)
	{
		return true;
	}
	
	// Check if present index and index
	// previous to it are in correct order
	// and rest of the array is also sorted
	// if true then return true else return
	// false
	return a[n - 1] >= a[n - 2] &&
	arraySortedOrNot(a, n - 1); // The array will keep returning false AND dump everything from the stack 
}

// Driver code
int main()
{
	int arr[] = { 20, 23, 23, 45, 78, 88 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Function Call
	if (arraySortedOrNot(arr, n))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
	return 0;
}

// This code is contributed by avanitrachhadiya2155
