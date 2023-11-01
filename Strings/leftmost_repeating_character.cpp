#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
const int CHAR = 256; 
 
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
One method is of cntArray. And I don't want to discuss the worst approach at all 

*/

/* Efficient Approach - 2 // Time Complexity: O(n + CHAR) ~= O(n). 
int leftMost(string &str)
{
	int len = str.length(); 
	bool visited[char]; 
	fill(visited, visited + CHAR, false); 
	
	int res = -1; 
	
	for(int i = str.length() - 1; i >= 0; i--)
	{
		if(visited[str[i]])
			res = i; 
			
		else 
			visited[str[i]] = true; 
	}
	
	return res; 
}
*/

void solve() // The method described in this function is the Optimized Solution - 1
{   
	// Do Something
	// memset OR fill  (Daniel Lemire states that on large datasets, memset is around 15x faster than fill, hence I use the former)
	string s;
	cin >> s; 
	int n = s.length(); 
	
	
	vector<char> firstIdx(CHAR, -1); 
	int res = INT_MAX; 
	
	for(int i = 0; i < n; i++)
	{
		int fi = firstIdx[s[i]]; 
		if(fi == -1)
			firstIdx[s[i]] = i; 
			
		else 
			res = min(res, fi); 
			
	}
	
	res = (res == INT_MAX) ? -1 : res; 
	
	cout << res << endl; 
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