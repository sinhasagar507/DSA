/* Maximum Subarray Sum - Kadane's algorithm */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum=0;
    cin>>n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++)  
        cin >> v[i];
        
    int ans=INT_MIN;
        
    for(int i=0; i<n; i++)
    {
       sum+=v[i];
       ans=max(ans, sum);
            
        if(sum<0)
            sum=0;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
