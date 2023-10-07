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

// Time Complexity: O(nlogn)
int ternary_search(vector<int> &v, int n, int low, int high, int key)
{
	if(low <= high)
	{
		int mid1 = low + (high-low)/3; 
		int mid2 = high - (high-low)/3; 
		
		if(v[mid1] == key)
			return mid1; 
			
		else if(v[mid2] == key)
			return mid2; 
			
		else if(key < v[mid1])
			return ternary_search(v, n, low, mid1-1, key); 
			
		else if(key > v[mid2])
			return ternary_search(v, n, mid2+1, high, key); 
			
		else
			return ternary_search(v, n, mid1+1, mid2-1, key); 
	}
	
	return -1; 
}

void solve()
{   
	int n, key; 
	cin >> n >> key; 

	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 
	
	int low = 0, high = n-1;
	ternary_search(v, n, low, high, key); 	
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