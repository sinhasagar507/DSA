/*
Problem Statement: Chocolate Pickup in a grid 
Problem Statement Link: https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
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
// Recursion. TC: O(3^(n+m). Each cell, 3 combinations for both of them) . Space Complexity: O(n)->Height of column 
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
	if(j1<0 or j2< 0 or j1>=c or j2>=c)
		return 1e-8; 
		
	if(i == r-1)
	{
		if(j1 == j2)
			return grid[i][j1]; 
			
		if(i == r-1)
		{
			if(j1 == j2)
				return grid[i][j1]; 
				
			else 
				return grid[i][j1] + grid[i][j2]; 
		}
	}
		
		// Explore all paths of Alice and Bob simultaneously 
		int maxi = -1e8; 
		
		for(int dj1 = -1; dj1 <= 1; dj1++)
		{
			for(int dj2 = -1; dj2 <= 1; dj2++)
			{
				int val = 0; 
				if(j1 == j2)
					val = grid[i][j1] + f(i+1, j1+dj1, j2+dj2, r, c, grid, dp); 
					
				else
					val = grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
					
				maxi = max(maxi, val); 
			}
		}
	return maxi; 
}
*/

/*
// Recursion + Memoization. Time Complexity: O(n*m*9). Space Complexity: O(n*m*m) -> DP + O(N) -> recursion stack space 
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
	// Now we know Alice starts from top-left corner and Bob takes off from top-right corner.
	// But since in each downgoing row, each of them can move one row to the left, one row to the right or one row to the bottom, these base cases (out of boundary) ones
	// can occur. Now we return 1e-8 instead of INT_MIN, cause there could arise a condition where 
	// grid[i][j1] and grid[i][j2] would be added together, then it could cause an overflow of INT_MIN+INT_MIN in the worst case scenario. 
	// which is outside of the bounds of int data type. Hence we return 1e-8
	if(j1<0 or j2<0 or j1>=c or j2>=c)
		return 1e-8; 
		
		
	// Now think deeply about each step (critical evaluation)
	// Here we have considered that both Alice and Bob are moving to the next row simultaneously
	// If we don't move them together, we might encounter a very long path. Moving each of them individually and then retreating backwards and cancelling out all those cases which have got occured together
	// Hence, adhering to this, we keep a track only of the current row and keep the columns separate in the form of j1 and j2  
	if(i == r-1) // If both are in the last row 
	{
		if(j1 == j2)
			return grid[i][j1]; // If both are in the same column 
			
		else 
			return grid[i][j1] + grid[i][j2]; // If both are in different columns 
	}
	
	if(dp[i][j1][j2] != -1) // This is the 3D DP array. The usual condition check 
		return dp[i][j1][j2]; 
		
		// Explore all paths of Alice and Bob simultaneously 
		int maxi = -1e8; 
		
		// Doing the delta stuff on grids 
		// There would be a total of 3*3=9 combos for Alice and Bob while going down the row 
		// For each of the Alice's moves(3), Bob can take his share of 3 moves 
		for(int dj1 = -1; dj1 <= 1; dj1++) // ((i+1, j-1), (i+1, j), (i+1, j+1)) for Alice 
		{
			for(int dj2 = -1; dj2 <= 1; dj2++) // ((i+1, j-1), (i+1, j), (i+1, j+1)) for Bob
			{
				int val = 0; 
				if(j1 == j2) // They can turn up in the same grid 
					val = grid[i][j1] + f(i+1, j1+dj1, j2+dj2, r, c, grid, dp); // Only one of them can take up all the grid's chocolates
					
				else // They can turn up in different grids 
					val = grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, r, c, grid, dp); // Both of them 
					
				maxi = max(maxi, val); 
			}
		}
	return dp[i][j1][j2] = maxi; // the max sum path from (first row, first col->Alice last col->Bob) will be returned   
}
*

/*
//Tabulation - Wrong 
for(int i = 0; i < r; i++)
{
	for(int j1 = 0, j2 = 0; j1 < c and j2 < c; j1++, j2++)
	// If Alice goes [i+1][j+1] way...Bob goes [i+1][j-1], [i+1][j] and [i+1][j+1]
	{
		int maxi = -1e8; 
		for(int dj1 = -1; dj1 <= 1; dj1++)
		{
			for(int dj2 = -1; dj2 <= 1; dj2++)
			{
				
				if(i == 0)
					dp[i][j1][j2] = grid[i][0] + grid[i][c-1];
				
				else if(j1 == 0 or j2 == 0)
					dp[i][j1][j2] =  or j1 == c-1 or j2 == c-1)
					dp[i][j1][j2] = grid[i][j1][j2]; 
					
				else 
				{
					maxi = max(maxi, dp[i-1][j+dj1][j+dj2]); 
					if(j1 == j2)
						dp[i][j1][j2] =  grid[i][j1] + maxi;
						
					else 
						dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxi; 
				}
			}
		}
	}
	
	int res = 0; 
	for(int k = 0; j < c; j++)
		for(int l = 0, l < c; l++)
			res = max(res, dp[r-1][j1][j2]); 
	
	return res; 
}

// j1 = 0 AND j2 = m-1 

// Tabulation - Wrong 
for(int i = n-2; i >= 0; i--)
{
	for(int j1 = 0, j2 = 0; j1 < c and j2 < c; j1++, j2++) // No this doesn't work, because the starting point of this cell is just 1, which is not always the case 
	// If Alice goes [i+1][j+1] way...Bob goes [i+1][j-1], [i+1][j] and [i+1][j+1]
	{
		int maxi = -1e8; 
		for(int dj1 = -1; dj1 <= 1; dj1++)
		{
			for(int dj2 = -1; dj2 <= 1; dj2++)
			{
				
				if(i == 0)
					dp[i][j1][j2] = grid[i][0] + grid[i][c-1];
				
				else if(j1 == 0 or j2 == 0)
					dp[i][j1][j2] =  or j1 == c-1 or j2 == c-1)
					dp[i][j1][j2] = grid[i][j1][j2]; 
					
				else 
				{
					maxi = max(maxi, dp[i-1][j+dj1][j+dj2]); 
					if(j1 == j2)
						dp[i][j1][j2] =  grid[i][j1] + maxi;
						
					else 
						dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxi; 
				}
			}
		}
	}
	
	int res = 0; 
	for(int k = 0; j < c; j++)
		for(int l = 0, l < c; l++)
			res = max(res, dp[r-1][j1][j2]); 
	
	return res; 
}
*/

int f(int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
	// Here the dp array stores all possible states where Alice and Bob could be (in all columns of a particular row)
	// Procedure: 1. Write the base case...2. Convert all states to loops. 3. Write rest of the conditions as they are 
	// Base Case 
	
	// int below[c][c]; -> Space Optimization 
	// int curr[c][c]; -> Space Optimization 
	for(int j1 = 0; j1 < c; j1++)
	{
		for(int j2 = 0; j2 < c; j2++)
		{
			if(j1 == j2)
				dp[r-1][j1][j2] = grid[r-1][j1]; 
				// below[j1]j2] = grid[r-1][j1]; 
				
			else
				dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2]; 
		}
	}
	
	// Recursive Intuition. I wouldn't go for 5 for loops man...its not good 
	for(int i = r-2; i >= 0; i--)
	{
		for(int j1 = 0; j1 < c; j1++)
		{
			for(int j2 = 0; j2 < c; j2++)
			{
				int maxi = -1e8; 
				for(int dj1 = -1; dj1 <= 1; dj1++) // ((i+1, j-1), (i+1, j), (i+1, j+1)) for Alice 
				{
					for(int dj2 = -1; dj2 <= 1; dj2++) // ((i+1, j-1), (i+1, j), (i+1, j+1)) for Bob
					{
						int j1_delta = j1 + dj1; 
						int j2_delta = j2 + dj2; 
						int val = 0; 
						
						if(j1 == j2) // They can turn up in the same grid
							val = grid[i][j1]; // Only one of them can take up all the grid's chocolates
								
						else // They can turn up in different grids 
							val = grid[i][j1] + grid[i][j2]; // Both of them 
						
				
						if(j1_delta >= 0 and j1_delta <= c-1 and j2_delta >= 0 and j2_delta <= c-1) // If traversing within the bounds 
							val += dp[i][j1_delta][j2_delta]; 
						
						else 
							val += (-1e8);
						
						maxi = max(maxi, val); 
					}
				}
				
				dp[i][j1][j2] = maxi; 
			}
		}
	}
	
	return dp[0][0][c-1];
}

int f(int r, int c, vector<vector<int>> &grid, vector<vector<int>> )

void solve()
{   
	// Do Something 
	int r, c; 
	cin >> r >> c; 
	
	vector<vector<int>> grid(r, vector<int>(c)); 
	
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cin >> grid[i][j]; 
		} 
	}
	
	// int dp[i][c1][c2]. Declare a 3D vector 
	vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
	
	// cout << f(0, 0, c-1, r, c, grid, dp) << endl; // RECURSION + MEMOIZATION 
	cout << f(0, 0, grid, dp) << endl; // TABULATION 
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