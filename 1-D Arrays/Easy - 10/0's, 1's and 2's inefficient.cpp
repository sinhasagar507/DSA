/* Given an array of 0s, 1s and 2s, sort the array in ascending order. Apply Dutch National Flag Algorithm from now on. */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    vector<int> freq(3, 0);
    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < freq[i]; j++)
            cout << i << " ";
    }
        
    cout << endl;
}
