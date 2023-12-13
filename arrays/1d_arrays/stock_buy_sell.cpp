/* 
Stock, buy and sell: Efficient solution O(n) 
*/

#include<bits/stdc++.h>
using namespace std;

int main()	
{
    int n, sum=0;
    cin>>n;
    vector<int> v(n);
   
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    int profit=0, initial=v[0]; 
    
    for(int i=1; i<n; i++)
    {
        if(price[i] > price[i-1])
        	profit += (price[i] - price[i-1]); 
    }
        
    cout<<profit<<endl;
    
    return 0;
}

