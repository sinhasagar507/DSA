/* Leaders in an Array Problem */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n, largest;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    largest = v[n-1];
    cout << v[n-1] << " ";
    
    for(int i = n-2; i >= 0; i--)
    {
        if(v[i] > largest)
        {
            cout << v[i] << " ";
            largest = v[i];
        }
    }
    
    cout << endl;
}
