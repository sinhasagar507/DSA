/* Hoare's partition. Similar to Lomuto's but the first element is considered as the pivot element.*/

#include<bits/stdc++.h>
using namespace std;

// this is where the difference between both partition lies.
int partition(vector<int> v, int n, int low, int high)
{   
    // the first element is considered as the pivot element in this case
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

int main()
{   
    int n;
    cin>>n;
    
    vector<int> v(n), temp;
    
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    cout<<partition(v, n, 0, n-1)<<endl;
    return 0;
}