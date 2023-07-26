/* Recursive code for linear jumps. */
#include<bits/stdc++.h>
using namespace std;
int cntPaths=0;

void dicePath(int n, int i, string osf)
{   
    if(i>=n)
        return;
    
    else if(i==n-1)
    {
        cntPaths++;
        cout<<osf<<endl;
        return;
    }
    
    for(int j=1; j<=n; j++)
        dicePath(n, j+i, osf+to_string(j)+"->");
}

int main()
{  
    dicePath(4, 0, "");
    return 0;
}
