/* Binary Search based square root of an element - Iterative Version. Rounded off to the floor value. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int element;
    cin>>element;
    
    int low=0, high=element, ans;
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        int sqr=mid*mid;
        
        if(sqr==element)
            return mid;
            
        else if(sqr>element)
            high=mid-1;
            
        else
        {
            low=mid+1;
            ans=mid;
        }
    }
        
    cout<<ans<<endl;
    return 0;
}
