/* There are n cells arranged in linear fashion. You have a dice with 6 faces [1, 2, 3, 4, 5, 6]. You are 
   standing on the 0th cell and want to reach (n-1)th cell. At each cell you can have 6 possible jumps to make.  
 */
#include<bits/stdc++.h>
using namespace std;
int cntPaths=0;

void dicePath(int n, int i, string osf)
{   
    if(i>n)
        return;
    
    else if(i==n)
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
