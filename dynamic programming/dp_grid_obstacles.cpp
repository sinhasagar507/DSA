/*
Problem Statement - DP Unique Grid Paths: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9
CodeStudio Link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

Thought Process:
-> Refer notes here: https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/

The approach from memoization -> tabulation 
1. Declare a base case 
2. Express all states in for loops 
3. Copy the recurrence and write again 

If there is a previous row and a previous column, we can space optimize it 
*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
 
template <class T>
	ll giveNcR(ll n, ll r){ll p = 1, k = 1; if(n-r < r) r = n - r; if(r != 0){while(r) {p *=n; k *=r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; 
	return p;}
	
 
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
int no_of_digits(ll n){return 1 + floor(log10(n));}
 
vector<int> graph[N+1];
bool visited[N+1];
int dist[N+1];
int source[N+1];
queue<int> node_queue;

/*
// Recursive Code 
// Time Complexity: O(2^(m*n)). Space Complexity: O(m+n) due to recursion stack 
int f(int i, int j)
{
	
	if(i == 0 and j == 0)
		return 1; 
		
	if(i < 0 or j < 0)
		return 0; 
		
	if(dp[])
	
	int up = f(i-1, j); 
	int left = f(i, j-1); 
	
	return up+left; 
	
}
*/


// Memoization + Recursion
// Time Complexity: O(m*n). Space Complexity: O(m*n)
/*
int f(int i, int j, vector<vector<int>> &dp)
{
	if(i == 0 and j == 0)
		return 1; 
		
	if(i < 0 or j < 0)
		return 0; 
		
	if(i>=0 and j>=0 and )
	if(dp[i][j] != -1)
		return dp[i][j]; 
		
	int up = f(i-1, j); 
	int down = f(i, j-1); 
	
	return dp[i][j] = up + left; 
}
*/

// Tabulation 
int f(int m, int n, vector<vector<int>> &dp)
{
	// Base Case. Write it as it is 
	dp[0][0] = 1; // Here the dp[m][n ]indicates the total possible no of ways for a grid of size m*n 
	
	// Represent all states in the form of loops 
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			
			if(i == 0 and j == 0)
				dp[i][j] = 1; 
				
			else
			{
				int down = 0, right = 0;
			
				if(i > 0) 
					down = dp[i-1][j]; 
				
				if(j > 0)
					right = dp[i][j-1]; 
				
				dp[i][j] = down + right; 
			}
		}
	}
	
	return dp[m-1][n-1]; 
}


// Tabulation + Space Optimization 
// Now remember that space optimization isn't only done in terms of prev and curr variables. Try smaller arrays???
int f(int m, int n)
{
	vector<int> prev(n, 0); 
	
	// Represent all states in the form of loops 
	for(int i = 0; i < m; i++)
	{
		vector<int> curr(n, 0); 
		for(int j = 0; j < n; j++)
		{
			
			if(i == 0 and j == 0)
				curr[j] = 1; 
				
			else
			{
				int down, right;
			
				if(i > 0) 
					down = prev[j]; 
				
				if(j > 0)
					right = curr[j-1]; 
					
				curr[j] = down + right; 
				
			}
			
			prev = curr; // Here the curr array is the temp array 
		}
	}
	
	return prev[n-1]; 
}

int uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return f(m, n, dp); 
}

/*
int uniquePaths(int m, int n)
{
	return f(m-1, n-1); 
}
*/

void solve()
{   
	// Do Something 
	int m, n; 
	cin >> m >> n; 
	
	cout << uniquePaths(m, n) << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin >> t;
 
	while(t--){
	solve(); 
	}
}