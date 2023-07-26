/* Given an array, print binary strings */

#include<bits/stdc++.h>
using namespace std;

void binaryString(int n, int i, string osf)
{   
    if(osf.length() == n)
    {
      cout<<osf<<endl;
      return;
    }
    
    binaryString(n, i+1, osf+'0');
    
    if(osf[i]!='1')
        binaryString(n, i+1, osf+'1');
}


int main()
{  
    int n;
    cin>>n;
  
    binaryString(n, 0, "0");
    binaryString(n, 0, "1");
    
    return 0;
}
