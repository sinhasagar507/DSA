/* Binary Search - Iterative version. Write Recursive version as and when required. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum=0, res=0, element;
    cin>>n>>element;
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    sort(v.begin(), v.end());
        
    int low=0, high=n-1, index=-1;
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(v[mid]==element)
        {
            index=mid;
            break;
        }
        
        if(v[mid]>element)
            high=mid-1;
            
        else if(v[mid]<element)
            low=mid+1;
    }
    
    if(index==-1)
        cout<<"The element is not present in the array"<<endl;
    else
        cout<<index<<endl;
        
    return 0;
}

