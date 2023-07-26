/* Stock, buy and sell-a  */

#include<bits/stdc++.h>
using namespace std;

int main()	
{
    int n, sum=0;
    cin>>n;
    vector<int> v(n);
   
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    int ans=0, initial=v[0]; 
    
    for(int i=1; i<n; i++)
    {
        if(v[i]-initial>ans)
            ans=v[i]-initial;
            
        if(initial>v[i])
            initial=v[i];
    }
        
    cout<<ans<<endl;
    
    return 0;
}

