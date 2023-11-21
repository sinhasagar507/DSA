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

void solve()
{   
	int m, n; 
	cin >> m >> n; // Input sizes of both arrays 
	vector<int> v(m), v1(n);  
	
	for(int i = 0; i < m; i++)
		cin >> v[i];
		
	for(int j = 0; j < n; j++)
		cin >> v1[j];
	
	/*	
	out[0] = v[0]; 
	for(int i = 1; i < m; i++)
		if(v[i] != v[i-1])
			out[i] = v[i]; 
			
	out[m] = v1[0]; 
	for(int j = 1; j < n; j++)
		if(v1[j] != v1[j-1])
			out[m+j] = v1[j];
	To be continued later. The solution can be approached using hashing. 
	*/ 
	
	int k = 0, l = 0; 
	while((k < m) and (l < n))
	{
		if((k != 0) and (v[k] == v[k-1]))
		{
			k++; 
			continue; 
		}
		
		else if((l != 0) and (v1[l] == v1[l-1]))
		{
			l++; 
			continue; 
		}
		
		else if(v[k] < v1[l])
		{
			cout << v[k] << " "; 
			k++; 
		}
		
		else if(v[k] > v1[l])
		{
			cout << v1[l] << " "; 
			l++; 
		}
		
		else
		{
			cout << v[k] << " "; 
			k++; 
			l++; 
		}

	}
	
	while(k < m){
		cout << v[k] << " "; 
		k++; 
	}
	
	while(l < n){
		cout << v1[l] << " "; 
		l++; 
	}

	cout << endl; 
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