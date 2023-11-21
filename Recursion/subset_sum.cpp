/*
Problem Statement: Given a set of non-negative integers and a value sum, 
				   the task is to check if there exists a subset of the 
				   given set whose sum is equal to the given sum. 
				   
Example Test Cases are as follows:  
4 
5 8 
10 5 2 3 6 
3 4 
1 2 3 
3 37 
10 20 15 
3 0 
10 20 15 

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

int subset_sum(vector<int> &v, int n, int sum, int idx)
{
	// Base Case and Self Work 
	if(idx == n)
		return sum == 0 ? 1 : 0;
		
	
	// Recursive Intuition
	return subset_sum(v, n, sum, idx+1) + subset_sum(v, n, sum-v[idx], idx+1); 
	
}

void solve()
{   
	// Do Something 
	int n, sum; 
	cin >> n >> sum; 
	
	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
		
	cout << subset_sum(v, n, sum, 0) << "\n";  
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