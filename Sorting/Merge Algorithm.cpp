/* Merge Sort */

#include<bits/stdc++.h>
using namespace std;


vector<int> merge(vector<int> v, int n, int low, int mid, int high)
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
        
    return v;
}


int main()
{  
    int n, largest;
    cin >> n;
    
    vector<int> v(n), v1(n);
    
    for(int i=0; i<n; i++)
        cin >> v[i];
      
    /* low<=mid<high*/    
    int low=0, high=n, mid=n+1/2;
    
    v = merge(v, n, low, mid, high);
    
    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    
    
    cout << endl;
}
