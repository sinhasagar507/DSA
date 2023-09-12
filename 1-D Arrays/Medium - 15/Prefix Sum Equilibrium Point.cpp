/* Equilibrium Index in an Array

   The equilibrium index of an array is an index such that the sum of elements at lower indexes 
   is equal to the sum of elements at higher indexes 
   
   Amortized Time Complexity: 

 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum=0;
    cin >> n;
    bool f = false;
    vector<int> v(n);
    
    for(int i=0; i<n; i++)  
        cin >> v[i];
    
    int lsum=0;
    
    for(int i=0; i<n; i++)
        sum += v[i];
    
    for(int i=0; i<n; i++)
    {
        if(lsum == sum-v[i])
        {
            f = true;
            break;
        }
        
        lsum += v[i];
        sum -= v[i];
    }
    
    if(f == true)
        cout << "Yes" << endl;
    
    else
        cout << "No" << endl;
    
    return 0;
}
