/* Trapping Rainwater Problem. Naive Approach. */
#include<bits/stdc++.h>
using namespace std;

// Function to return the maximum
// water that can be 

/*
Inefficient Solution 
int maxWater(int arr[], int n) // Time Complexity: O(n^2). Space Complexity: O(1)
{
	
	// To store the maximum water
	// that can be stored. Being at the first index won't save any water as the region is uncovered
	int res = 0;
	
	// For every element of the array
	for (int i = 1; i < n-1; i++) {
		
		// Find the maximum element on its left
		int left = arr[i];
		for (int j=0; j<i; j++)
		left = max(left, arr[j]);
		
		// Find the maximum element on its right
		int right = arr[i];
		for (int j=i+1; j<n; j++)
		right = max(right, arr[j]);
		
	// Update the maximum water
	res = res + (min(left, right) - arr[i]);
	}

	return res;
}
*/

// Efficient Solution 
int maxWater(int arr[], int n) // Time Complexity: O(n). Space Complexity: O(1)
{
    int res = 0;  
    lmax[0] = arr[0], rmax[n-1] = arr[n-1];
    
    for(int i=1; i<n; i++)
        lmax[i] = max(lmax[i-1], arr[i]);
     
    for(int j=n-2; j>=0; j--) 
        rmax[j] = max(rmax[j+1], arr[j]);
        
    for(int k=0; k<n; k++)
        res += min(lmax[k], rmax[k])-arr[k];
        
    return res;
}


// Driver code
int main()
{
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << maxWater(arr, n);
	
	return 0;
}
