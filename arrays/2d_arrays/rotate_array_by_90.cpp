/* Rotate a matrix by 90 degrees. First do transposition of the matrix. Then perform a row swap. */
/* Efficient solution */

#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int m, n;
    cin>>m>>n;
    
    vector<vector<int>> v(m+1 , vector<int> (n+1));

    for(int i=1; i<m+1; i++)
        for(int j=1; j<n+1; j++)
            cin>>v[i][j];
            
    //First do transpostion
    for(int i=1; i<=m; i++)
    {
        for(int j=i+1; j<=n; j++)
            swap(v[i][j], v[j][i]);
    }
    
    // Then do row swap
    for(int i=1; i<=m/2; i++)
    {
        for(int j=1; j<=n; j++)
            swap(v[i][j], v[m-i+1][j]);
    }
    
    cout<<endl;
    
      for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++)
            cout<<v[i][j]<<" ";
            cout<<endl;
      }
            
    return 0;   
}