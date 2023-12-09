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

int find(int x, vector<int> &parent)
{
	if(parent[x] == x)
		return x; 
		
	else 
		find(parent[x], parent); 
}

void union(int x, int y, vector<int> &parent, vector<int> &ranks)
{
	int x_rep = find(x); 
	int y_rep = find(y); 
	
	if(x_rep == y_rep)
		return; 
		
	if(ranks[x_rep] < ranks[y_rep])
		parent[x_rep] = y_rep; 
		
	else if(ranks[y_rep] < ranks[x_rep])
		parent[y_rep] = x_rep; 
		
	else
	{
		parent[y_rep] = x_rep; 
		ranks[x_rep]++; 
	} 
}

void solve()
{   
	int n; 
	cin >> n; // Enter the initial no. of disjoint sets 
	
	vector<int> parent(n), ranks(n); 
	
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
		ranks[i] = i;  
	}
 
 
 	// Do DSU for q queries 
 	
 	int q; 
 	cin >> q; 
 	
 	while(q)
 	{
 		int a, b; 
 		union(a, b, parent, ranks); 
 	}
 	
 	for(int i = 0; i < n; i++)
 		cout << parent[i] << " "; 
 		
 	cout << "\n"; 
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