#include<bits/stdc++.h>
using namespace std;

// The beauty of recursion. Max-Heap is represented as an array, but pictorially represented as a heap
// In practice, MergeSort takes theta(nlogn) time on average(not only om average, but in all 3 cases, i.e., best case, average case and worst case). But Quicksort and MergeSort are still widely used. 
void maxHeapify(vector<int> &v, int n, int i)
{
	int largest = i, left = 2*i+1, right=2*i+2;
	
	if(left<n and v[largest]<v[left]) largest = left;
	if(right<n and v[largest]<v[right]) largest = right;
	
	if(largest != i)
	{
		swap(v[largest], v[i]);
		
		// Iterate till the child node 
		maxHeapify(v, n, largest);
	}
}

void heapSort(vector<int> &v, int n)
{
	// Build Heap 
	for (int i=n/2-1; i>=0; i--)
		maxHeapify(v, n, i);

	// One by One extract element from heap 
	for(int i=n-1; i>=0; i--)
	{
		swap(v[0], v[i]);
		maxHeapify(v, i, 0); 
	}
}

int main()
{
	int n;
	cin>>n;
	
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
		cin>>v[i];
		
	for(int i=(n-2)/2; i>=0; i--)
		maxHeapify(v, n, i);
	
		
	heapSort(v, n);
	
	for(int i=0; i<n; i++)
		cout<<v[i]<<" ";
		
	cout<<endl;
	
	return 0;
}