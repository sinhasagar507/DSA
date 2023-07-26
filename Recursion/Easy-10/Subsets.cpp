/* Given an array, print all of its subsets */

#include<bits/stdc++.h>
using namespace std;

void stringSubset(vector<int> v, int n, int i, string osf)
{   
    if(i==n)
    {
      cout<<"["<<osf<<"]"<<endl;
      return;
    }
    
    /* Include the sub-element once */
    stringSubset(v, n, i+1, osf+to_string(v[i])+',');
    
    /* Don't include the sub-element */
    stringSubset(v, n, i+1, osf);
    
}


int main()
{  
    int n;
    cin>>n;
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin>>v[i];
        
    stringSubset(v, n, 0, " ");

    
    return 0;
}
