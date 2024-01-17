/*
Problem Statement: 0-1 Knapsack 
				   https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
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
// Recursive Code. Time Complexity: O(2^n). Space Complexity: O(recursion stack space) = O(row length)
f(i, j)
{
	if(i == 0)
		return (weight/sack_weight[i]) * sack_val[i]; 
		
	int notTake = 0 + f(i-1, j); 

	if(weight >= sack_weight[i])
		int take = sack_val[i] + f(i, weight-sack_weight[i]); // We will keep including the sack until both become 0 
		
	return max(take, notTake); 
}
*/

// DP-based solution 
// Here the dp array represents the maximum value of the stolen items at any point 
// Write the base case as it is 

// 
/*
Time Complexity: Almost Exponential 
Space Complexity: O(w) 
f(i, j)
{
	if(i == 0)
		return (weight/sack_weight[i]) * sack_val[i]; 
		
	if(dp[i][weight] != -1)
		return dp[i][weight]; 
		
	int notTake = 0 + f(i-1, j); 

	if(weight >= sack_weight[i])
		int take = sack_val[i] + f(i, weight-sack_weight[i]); // We will keep including the current sack's value until the original sack's  value becomes 0 
		
	return dp[i][weight] = max(take, notTake); 
}
*/

// All vals from 0 to max_val  
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
	vector<vector<int>> table(n, vector<int>(w+1)); 
	
	// Here the first index of table array refers to the index, whereas the second index refers to all of the maximum possible values of weight 
	for(int weight_val = 0; weight_val <= w; weight_val++)
		table[0][weight_val] = (weight_val/weight[0]) * profit[0]; 
		
	for(int i = 1; i < n; i++)
	{
		for(int weight_val = 0; weight_val <= max_weight; weight_val++)
		{
			int notTake = 0 + table[i-1][weight_val]; 
			
			int take = 0; 
			if(weight_val >= weight[i])
				take = profit[i] + table[i][weight_val-weight[i]]; 
				
			table[i][weight_val] = max(take, notTake); 
		}
	}
	
	return table[n-1][w]; 
}

// Space Optimization 
int unboundedKnapsack(int n, int w, vector<int>& profit, vector<int> &weight)
{
	vector<vector<int>> prev(weight, 0), curr(weight, 0); 
	
	// Here the first index of table array refers to the index, whereas the second index refers to all of the maximum possible values of weight 
	for(int weight_val = 0; weight_val <= w; weight_val++)
	{
		prev[weight_val] = (weight_val/weight[0]) * profit[0]; 
		curr[weight_val] = (weight_val/weight[0]) * profit[0]; 
	}
		
	for(int i = 1; i < n; i++)
	{
		for(int weight_val = 0; weight_val <= max_weight; weight_val++)
		{
			int notTake = 0 + prev[weight_val]; 
			
			int take = 0; 
			if(weight_val >= weight[i])
				take = profit[i] + curr[weight_val-weight[i]]; 
				
			curr[weight_val] = max(take, notTake); 
		}
		
		prev = curr; 
	}
	
	return prev[w]; 
}

void solve()
{   
	// Do Something 
	int n, w; 
	cin >> n >> w; 
	
	vector<int> weight(n), profit(n); 
	
	for(int i = 0; i < n; i++)
	{
		cin >> weight[i]; 
		cin >> profit[i]; 
	}
	
	cout << unboundedKnapsack(n, w, profit, profit) << endl; 

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