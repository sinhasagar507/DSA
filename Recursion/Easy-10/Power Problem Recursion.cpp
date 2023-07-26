/* Power Problem in Recursion */

#include<bits/stdc++.h>
using namespace std;

// Recursive Power Function 
int power(int a, int b)
{   
    if(a!=0 and b==0)
            return 1;
        
    return a*power(a, b-1);
}

// Another Methodology 
/* 
int powerRecursive(int a, int b)
{
    // Base Case 
    if (b==0)
        return 1; 

    if (b==1)
        return a; 

    // Recursive Assumption 
    int temp = powerRecursive(a, b/2); 

    // Self-Work 
    if (b%2==0) 
    {
        return temp*temp; 
    }
}


*/

int main()
{  
    int a, b;
    cin>>a>>b;
    cout<<power(a, b)<<endl;
    
    return 0;
}
