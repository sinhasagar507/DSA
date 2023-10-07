/*



*/ 

#include <bits/stdc++.h>
using namespace std;


/*
Inefficient soluion 

void kthSmallest(int arr[], int n, int k)
{
	sort(arr.begin(), arr.end()); // Takes O(nlogn) time at most 
	return arr[k-1]; 
}


*/

int partition(int arr[], int l, int h) // At the very max, this array would run O(n) time, and that too when the array is sorted
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}

int kthSmallest(int arr[],int n,int k){
    int l=0,r=n-1;
    while(l<=r){
        int p=partition(arr,l,r);
        if(p==k-1)
            return p;
        else if(p>k-1)
            r=p-1;
        else
            l=p+1;
    }
    return -1;
}
 
int main() {
	
    int arr[]={10,4,5,8,11,6,26};
	
	int n=sizeof(arr)/sizeof(arr[0]);int k=5;
	
	int index=kthSmallest(arr,n,k);
	
	cout<<arr[index];
	
}