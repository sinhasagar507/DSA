/** Sliding Window Technique **/
/** Add one and subtract one **/
/** Maximum Contiguous Subarray Sum**/
/** Implementation in O(n) time and O(1) auxiliary memory space**/

/** An extension of the implemented algorithm can be posed in the form of a question as - Given an unsorted array of non-negative integers. Find if there is a subarray with a given sum. Next Page**/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for(int i=0; i<n; i++)  
        cin >> v[i];
    
    int curr_sum = 0, max_sum = 0;
    
    for(int i = 0; i < k; i++)
        curr_sum += v[i];
    
    max_sum = curr_sum;
    
    for(int i = k; i < n; i++)
    {
        curr_sum += (v[i] - v[i-k]);
        max_sum = max(max_sum, curr_sum);
    }
        
    cout << max_sum << endl;
    return 0;
}
