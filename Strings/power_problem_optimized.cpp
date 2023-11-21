/* 
Problem Statement: Given a number and its reverse, find that number raised to the 
				   power of its own reverse mod n where n = pow(10, 9) + 7 
				
				
Input:
N = 12, R = 21
Output: 864354781
Explanation: The reverse of 12 is 21and 1221 when divided by 1000000007 
gives remainder as 864354781 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    int n = pow(10, 9) + 7; 
    
    long long power(int N, int R)
    {
        //Your code here
        if (R == 0)
            return 1; 
        if (R == 1)
            return N; 
            
        long long val = ((power(N, R/2)%n) * (power(N, R/2)%n))%n; 
            
        if (!(R%2))
            return val; 
            
        else 
            return (val * (N%n))%n; 
    }

};

//{ Driver Code Starts.

// compute reverse of a number. TIme and Space Complexity of this program: O(log(n))
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}

int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends