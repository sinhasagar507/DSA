/* Maximum subarray sum using two pointer approach. Find the indexes as well. I guess this can be implemented using Kadane's algorithm

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4
Sum of elements between indices
2 and 4 is 20 + 3 + 10 = 33

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: Sum found between indexes 1 and 4
Sum of elements between indices
1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: No subarray found
There is no subarray with 0 sum

The worst case time complexity of this algorithm is O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;
    bool flg=false;
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int curr_sum=v[0], lptr=0;
     
    for(int i=0; i<n; i++)
    {   
       while(curr_sum > sum and lptr<i)
       {
            curr_sum-=v[lptr];
            lptr++;
       }
       
       if(curr_sum==sum)
       {    
            flg=true;
            cout << "Sum found between indexes " << lptr << " and " << i;
            break;
       }
       
       if(i<n)
            curr_sum+=v[i];
    }
    
    if(!flg)
        cout<<"No subarray found" << endl;
    
    return 0;
}
