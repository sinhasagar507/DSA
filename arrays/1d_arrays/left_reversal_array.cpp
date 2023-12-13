/*
Problem Statement: Left Rotation of an Element by D places. Left Rotation means a rotation that happens counterclockwise. 
				   The elements are moved counterclockwise by D places, which results in the elements moving back by D positions 
				   from their initial position
*/ 

#include<bits/stdc++.h>
using namespace std;

/* Inefficient method for left rotation. Time Complexity: O(nd). Space Complexity: O(1)
void lRotateOne(int arr[], int n)
{
	int temp = arr[0]; 
	
	for(int i = 1; i < n; i++)
		arr[i-1] = arr[i]; 
		
	arr[n-1] = temp; 
}

void leftRotate(int arr[], int d, int n)
{
	for(int i = 0; i < d; i++)
		leftRotate(arr, n); 
}
*/

/* Another Method. Time Complexity: O(max(d, n-d)). Space Complexity: O(d)
void leftRotate(int arr[], int d, int n)
{
	int temp[d];

	for(int i = 0; i < d; i++)
	{
		temp[i] = arr[i];
	}

	for(int i = d; i < n; i++)
	{
		arr[i - d] = arr[i];
	}

	for(int i = 0; i < d; i++)
	{
		arr[n - d + i] = temp[i];
	}	
}
*/

// Efficient Solution 
void reverse(int arr[], int low, int high)
{
	while(low < high)
	{
		swap(arr[high], arr[low]); 
		low++; 
		high--; 
	}
}

void leftRotate(int arr[], int d, int n)
{
	reverse(arr, 0, d-1); 
	reverse(arr, d, n-1); 
	reverse(arr, 0, n-1); 
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, n = 5, d = 2; 
     
    cout << "Before Rotation" << endl;
    for(int i = 0; i < n; i++)
    	cout << arr[i] << " ";
    	
    cout << endl; 
    
    leftRotate(arr, d, n); 
    
    cout << "After Rotation" << endl; 
    
    for(int i = 0; i < n; i++)
    	cout << arr[i] << " "; 
   
    return 0;
}