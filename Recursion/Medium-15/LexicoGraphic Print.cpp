/* Recursive code for lexicographic string printing order. */

#include<bits/stdc++.h>
using namespace std;

void lexicoGraphicOrder(int n, int i)
{
    // Base Case 
    if(i>n)
        return;
        
    // Self Work 
    cout<<i<<endl;
    
    // Recursive Intuition
    for(int j=(i==0)?1:0; j<=9; j++)
        lexicoGraphicOrder(n, 10*i+j);

}

int main()
{  
    int n;
    cin>>n;
    
    int i=1;
    lexicoGraphicOrder(n, 0);
    return 0;
}
