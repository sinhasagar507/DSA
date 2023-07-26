/* Merge Sort */

#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &v, int n, int low, int mid, int high)
{
    int n1=mid-low+1, n2=high-mid;
    vector<int> a(n1), b(n2);
    
    for(int i=0; i<n1; i++)
        a[i]=v[low+i];
    for(int i=0; i<n2; i++)
        b[i]=v[mid+i+1];
        
    int i=0, j=0, k=low;
    
    while(i<n1 and j<n2)
    {
        if(a[i]<=b[j])
            v[k++]=a[i++];
        else
            v[k++]=b[j++];
    }
    
    while(i<n1)
        v[k++]=a[i++];
    while(j<n2)
        v[k++]=b[j++];
}

void mergeSort(vector<int> &v, int n, int low, int high)
{
	if(low>=high)
		return;
		
	int mid = (low+high)/2;
	mergeSort(v, n, low, mid);
	mergeSort(v, n, mid+1, high);
	merge(v, n, low, mid, high);
}

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin >> v[i];
      
    /* low<=mid<high*/  
    mergeSort(v, n, 0, n-1);
    
    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    
    cout << endl;
}
