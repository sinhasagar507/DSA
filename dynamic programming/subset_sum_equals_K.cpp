/*
Problem Statement: From now on, thinking about the subset sum approach 

1. Express (ind, target) 
2. Explore possibilities of that index 
3. Return true/false on that index 
   a[idx] part of the subsequence / a[ind] not part of the subsequence 

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

// Recursive Code. Time Complexity: O(2^n). Space Complexity: O(N) -> the usual recursion stack space
/* 
bool f(vector<int>& v, vector<int>& n, int i, int target)
{
	// Base Case(s) 
	if(target == 0)
		return true; 
		
	if(i == 0)
		return v[0] == target; 
	
	// Recursive Intuition 
	bool notTake = f(v, n, i-1, target); 
	
	bool take = false; // initially set to false because we would be checking if jumping on to the next(here, previous index) would make the target negative or not  
	
	// If target - v[i] >= 0, then only roll ahead...else don't 
	if(target-v[i] >= 0)
		bool take = f(v, n, i-1, target-v[i]); 
		
	// Self Work 
	return (notTake or take);
}
*/
// memo array is int since it should have some initial integer value. Now, I can't keep these initial values as boolean naa...So I will do the OR operations and store them as 0 or 1
// Time Complexity of the solution: O(n*m). Space Complexity: O(n*m) + O(N) -> memo array + recursion stack 
/*
int f(vector<int>& v, vector<int>& n, vector<vector<int>>& memo, int i, int target)
{
	// Base Case(s) 
	if(target == 0)
		return true; 
		
	if(i == 0)
		return v[0] == target; 
		
	if(memo[i][target] != -1)
		return memo[i][target]; 
		
	
	// Recursive Intuition 
	bool notTake = f(v, n, memo, i-1, target); 
	
	bool take = false; // initially set to false because we would be checking if jumping on to the next(here, previous index) would make the target negative or not  
	
	// If target - v[i] >= 0, then only roll ahead...else don't 
	if(target-v[i] >= 0)
		bool take = f(v, n, memo, i-1, target-v[i]); 
		
	// Self Work 
	return memo[i][target] = (notTake or take);
}
*/
// Tabulation 
/*
bool f(vector<int>& v, int n, int k)
{
	vector<vector<bool>> table(n, vector<bool>(target, false)); // The tabulation array 
	
	// Base Cases 
	// In whatever index the target becomes 0, return true
	for(int i = 0; i < n; i++)
		table[i][0] = true; 
	
	// In the 0th index, only for all those targets where target has reduced to a[0], return true 
	table[0][v[0]] = true; 
	
	// Now convert the states to loops 
	for(int i = 1; i < n; i++)
	{
	// Target is a desired sum...Now since I am building it from bottom up...kahin pe kmm value hoga 
		for(int target = 1; target <= k; target++)
		{
			bool notTake = table[i-1][target]; 
			bool take = false;
			
			if(target-v[i] >= 0)
				take = table[i-1][target-v[i]];
				
			table[i][target] = take or notTake; 
			
		}
	}

	return table[n-1][k]; 
}
*/

// Space Optimization 
bool f(vector<int>& v, int n, int k)
{
	
	// Since I have a 2D DP array, I can space optimize it to a 1D array 
	vector<bool> prev(k+1, false), curr(k+1, false); 
	
	// Base Cases 
	// In whatever index the target becomes 0, return true
 
	prev[0] = true; 
	curr[0] = true; 
	
	// In the 0th index, only for all those targets where target has reduced to a[0], return true 
	prev[v[0]] = true; 
	
	// Now convert the states to loops 
	for(int i = 1; i < n; i++)
	{
	// Target is a desired sum...Now since I am building it from bottom up...kahin pe kmm value hoga 
		for(int target = 1; target <= k; target++)
		{
			bool notTake = prev[target]; 
			bool take = false;
			
			if(target-v[i] >= 0)
				take = prev[target-v[i]];
				
			curr[target] = take or notTake; 
			
		}
		
		prev = curr; 
	}

	return prev[k]; 
}

void solve()
{   
	// Do Something
	int n, target; 
	cin >> n >> target; 
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 
		
	// vector<vector<int> memo(n, vector<int> (target, -1)); 
	
	// cout << f(v, n, n-1, target); 
	// cout << f(v, n, memo, n-1, target); 
	// cout << f(v, n, target); 
	cout << f(v, n, target) << endl; 
	
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