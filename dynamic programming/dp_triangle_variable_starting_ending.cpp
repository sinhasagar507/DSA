/*
Problem Statement: Triangle - fixed starting and variable ending points
				   https://www.codingninjas.com/studio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

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
	if(i == n-1)
		return a[n-1][j]; 
		
	down = a[i][j] + f(i+1, j); 
	diagonal = a[i][j] + f(i+1, j+1); 
	
	return min(down, diag); 
}
*/

// Memoization mein bhi bottom-up progression is possible
// Time Complexity: O(n). Space Complexity: O(n)
int f(vector<int> &v, vector<int> &dp, int n, int idx)
{
	if(i == n-1)
		return a[n-1][j]; 
		
	if(dp[i][j] != -1)
		return dp[i][j]; 
		
	int down = a[i][j] + 
		
	down = a[i][j] + f(i+1, j); 
	diagonal = a[i][j] + f(i+1, j+1); 
	
	return min(down, diag); 
}

/*
Tabulation Code 
// Time Complexity: O(n). Space Complexity(O(n))
void max_sum_non_adjacent(vector<int> &v, vector<int> &dp, int n, int idx)
{

}

//Space Optimization. Time Complexity: O(n). Space Complexity: O(1)
int max_sum_non_adjacent(vector<int> &v, vector<int> &dp, int n, int idx)
{
	
}
*/



void solve()
{   
	// Do Something 
	vector<int> v = {2, 1, 4, 9}; 
	int n = v.size();
	vector<int> dp(n, -1);  
	
	cout << max_sum_non_adjacent(v, dp, n, 0) << "\n"; 

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