/* Partition a given array around a given element. Standard naive approach and unstable. Separate out the unstable part yourself. */
#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n, k;
    cin>>n>>k;
    vector<int> v(n), temp;
    
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    int element=v[k-1];

    int cnt=0;
    for(int j=0; j<n; j++)
    {
        if(v[j]<=v[k-1] and j!=k-1)
            temp.push_back(v[j]);
    }
    
    temp.push_back(element);

    for(int j=0; j<n; j++)
    {
        if(v[j]>v[k-1] and j!=k-1)
            temp.push_back(v[j]);
    }
    
    for(auto it:temp)
        cout<<it<<" ";
    cout<<endl;
    
    return 0;
}