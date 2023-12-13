/* Search for an element in a sorted 2-D matrix(Row-Wise and Column-Wise) */
/* Naive solution known. Works in O(n^2). Trying out the efficient solution. */

#include<bits/stdc++.h>
using namespace std;
int x, m, n;
bool flg=false;

void search(vector<vector<int>> v, int m, int n, int rowindex)
{
    for(int j=1; j<=4; j++)
    {
        if(v[rowindex][j]==x)
            flg=true;
    }
}

int main()
{   
    cin>>m>>n>>x;
    
xv(m+1 , vector<int> (n+1));
    int i=1, j=n;
    bool flg=false;
    
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>v[i][j];
    
    while(i<=m and j>=1)
    {   
        if(v[i][j]==x)
        {
            cout<<"Element found"<<endl;
            flg=true;
            break;
        }
        
        else if(v[i][j]>x)
            j--;
            
        else
            i++;
            
    }
    
    if(flg==false)
        cout<<"Element not found"<<endl;
        
    return 0;   
}