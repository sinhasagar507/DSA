/* Partition a given array around a given element. Lomuto Partition. Unstable partitioning. Partitions in theta(n) time complexity, but constant space complexity. These operations form the bedrock of quick sort algorithm. */
#include<bits/stdc++.h>
using namespace std;

int findPartition(vector<int>v, int n, int low, int high)
{   
    // initial value of i is assigned to -1
    int i=low-1;
    int pivot=v[high];
    
    // loop through the array
    for(int j=low; j<=high; j++)
    {
        if(pivot>v[j])
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    
    // Swapping the pivot with the index at border of decreasing element window
    swap(v[i+1], v[high]);
    
    return (i+1);
}

// Some examples of the problem include {10, 30, 40, 90, 80, 50, 70} and {70, 60, 80, 40, 30}

int main()
{   
    int n, k;
    cin>>n>>k;
    vector<int> v(n), temp;
    
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    int pivotIndex=findPartition(v, n, 0, n-1);
    
    return 0;
}