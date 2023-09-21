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
        
    /*
    int ans=INT_MIN;
        
    for(int i=0; i<n; i++)
    {
       sum+=v[i];
       ans=max(ans, sum);
            
       if(sum<0)
       	sum=0;
    }
    */ 
    
    int res = v[0], maxEnding = v[0]; 
	for(int i = 1; i < n; i++){
		maxEnding = max(v[i], maxEnding + v[i]);
		res = max(res, maxEnding); 
	}
	
    cout<<res<<endl; 
    return 0;
}
