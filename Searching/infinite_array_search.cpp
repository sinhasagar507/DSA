// C++ program to demonstrate working of an algorithm that finds
// an element in an array of infinite size

#include<bits/stdc++.h>
using namespace std;

// Function for binary Search 
int binarySearch(int arr[], int low, int high, int elem)
{
	if(high >= low)
	{
		int mid = low + (high - low)/2;
		
		if(arr[mid] == x)
			return mid;
			
		else if(arr[mid] > x)
			return binarySearch(arr, low, mid-1, elem); 
			
		else
			return binarySearch(arr, mid+1, high, elem);  
	}
	
	return -1; 
}

// function takes an infinite size array and a key to be
// searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING


int main()
{
	/* Following is the naive approach for binary search in an infinite array 
    int n, element;
    cin>>n>>element;

    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(), v.end());

    int j=0, pos=-1;

    while(true)
    {   
        if(v[j]==element)
            pos=j;

        else if(v[j]>element)
            break;

        j++;
    }

    cout<<pos<<endl;
    
    */
    
    return 0;
}
