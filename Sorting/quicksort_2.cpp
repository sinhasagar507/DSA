/* QuickSort Algorithm */

// Based on Divide(Recursive division) approach
// Worst-Case Time Complexity(O(n^2))
// Despite O(n^2) being the worst case time-complexity of this algorithm, it is considered efficent because of the following reasons:
// 1. In-Place sorting algorithm. 
// 2. Cache-Friendly
// 3. Average time complexity is O(nlogn)
// 4. Its a tail-recursive algorithm

/* This implementation is based upon Hoare's partition. Similar to Lomuto's but the first element is considered as the pivot element. O(1) extra space but unstable. Analyse why Hoare's implementation is better than Lomuto's*/
#include<bits/stdc++.h>
using namespace std;

// this is where the difference between both partition lies. Here you can even apply Lomuto's partitioning, or the original stable version. 
int partition(vector<int> &v, int n, int low, int high)
{   
    // the first eleent is considered as the pivot element in this case
    int pivot=v[low];
    
    // no element is included in the window hence the index has been set to -1
    int i=low-1;
    
    // the last index is equivalent to the size of array
    int j=high+1;
    
    while(true)
    {
        do
            i+=1;
        while(v[i]<pivot);
        
        do 
            j-=1;
        while(v[j]>pivot);
        
        if(i>=j)
            return j;
            
        swap(v[i], v[j]);
    }
}

void quickSort(vector<int> &v, int n, int low, int high)
{
    if(low<high)
    {   
        int p=partition(v, n, low, high);
        quickSort(v, n, low, p);
        quickSort(v, n, p+1, high);
    }
}


int main()
{   
    int n;
    cin>>n;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin>>v[i];
    
    int low=0, high=n-1;
    quickSort(v, n, low, high);
    
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
        
    cout<<endl;
        
    return 0;
}