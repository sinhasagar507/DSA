/* Trapping Rainwater - Efficient solution */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum=0, res=0;
    cin>>n;
    vector<int> v(n), lmax(n), rmax(n);
   
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    lmax[0]=v[0], rmax[n-1]=v[n-1];
    
    for(int i=1; i<n; i++)
        lmax[i]=max(lmax[i-1], v[i]);
     
    for(int j=n-2; j>=0; j--) 
        rmax[j]=max(rmax[j+1], v[j]);
        
    for(int k=0; k<n; k++)
        res+=min(lmax[k], rmax[k])-v[k];
        
    cout<<res<<endl;
    return 0;
}

