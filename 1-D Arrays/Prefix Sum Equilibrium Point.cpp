/** Equilibrium Point based on Prefix Sum Technique - Inefficient solution **/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, pvt;
    cin >> n;
    vector<int> v(n);
    bool flag = false;
    
    for(int i=0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] < 0)
            flag = true;
    }
       
    if(flag == false)
        cout << "No" << endl;
    
    else
    {
        vector<int> preSum(n);
        bool flag1 = false;
        
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
                preSum[i] = v[i];
            else
                preSum[i] = preSum[i-1] + v[i];
        }
        
        for(int i = 0; i < n; i++)
        {   
            int lsum, rsum;
            
            if(i == 0)
            {
                lsum = 0;
                rsum = preSum[n-1] - v[0];
                
                if(lsum == rsum)
                {
                    pvt = v[i];
                    flag1 = true;
                    break;
                }
            }
            
            else if(i != 0)
            {
                lsum = preSum[i-1];
                rsum = preSum[n-1] - preSum[i];
                
                if(lsum == rsum)
                {
                    pvt = v[i];
                    flag1 = true;
                    break;
                }
            }
        }
        
        if(flag1 == false)
            cout << "No" << endl;
            
        else
        {
            cout << "Yes" << endl;
            cout << pvt << endl;
        }
            
    }
    return 0;
}
