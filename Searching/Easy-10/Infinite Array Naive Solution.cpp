/* Naive solution to finding an element in an infinite array */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, element;
    cin>>n>>element;

    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(), v.end());

    int j=0, pos=-1;

    while(true)
    {   
        if(v[j]==element)
            pos=j;

        else if(v[j]>element)
            break;

        j++;
    }

    cout<<pos<<endl;
    return 0;
}
