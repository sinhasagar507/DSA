/* Just change the higher indexes */
#include<bits/stdc++.h>
using namespace std;
    
int binarySearch(vector<int> v, int n, int low, int high, int element, int position)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]==element)
        {
            position=mid;
            break;
        }
    
        else if(v[mid]>element)
            high=mid-1;
    
        else if(v[mid]<element)
            low=mid+1;
    }
    
    return position;
}
    
int main()
{
    int n, element;
    cin>>n>>element;
    
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    
    if(v[0]==element)
        cout<<0<<endl;
    
    else if (v[1]==element)
        cout<<1<<endl;
    
    else 
    {   
        int i=1;
 
        while(i<n)
        {
            if (v[i]<element)
                i*=2;
        }
      
        int low=i/2, high=n-1;
    
        int pos=binarySearch(v, n, low, high, element, -1);
        cout<<pos<<endl;
    }
            
    return 0;
}
