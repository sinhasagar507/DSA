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

// Memoization mein bhi bottom-up progression is possible 
int max_sum_non_adjacent(vector<int> &v, vector<int> &dp, int n, int idx)
{
	// Base Case 1 
	if(idx == n-1)
		return v[n-1]; 
		
	// Base Case 2 
	else if (idx >= n)
		return 0; 
		
	// Base Case 3 
	if(dp[idx] != -1)
		return dp[idx]; 
		
	// Recursive Intuition 
	int noSum = 0 + max_sum_non_adjacent(v, dp, n, idx+1); 
	int sum = v[idx] + max_sum_non_adjacent(v, dp, n, idx+2); 
	
	// Self Work 
	dp[idx] = max(noSum, sum); 
	
	return dp[idx]; 
}



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