/* Recursive code for printing maze paths */

#include<bits/stdc++.h>
using namespace std;

int totalPaths=0;
void mazePath(int i, int j, int n, int m, string osf) 
{
    if(i==n-1 and j==m-1)
    {
        totalPaths++; 
        cout << osf << endl; 
        return;
    }

    else if(i>=n or j>=m)
        return; 

    mazePath(i+1, j, n, m, osf+"R"); // Right move 
    mazePath(i, j+1, n, m, osf+"D"); // Downward move
    mazePath(i+1, j+1, n, m, osf+"->") // Diagonal move
}

int main()
{  
    int n;
    cin>>n;
    
    int i=1;
    lexicoGraphicOrder(n, 0);
    return 0;
}
