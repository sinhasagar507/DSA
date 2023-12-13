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

bool checkDescending(vector<int> &v, int n)
{
	int desc_reverse_cnt = 0; 
	for(int i = n-2; i >= 0; i--)
	{
		if(v[i] < v[i+1]){
			desc_reverse_cnt++; 
		}
	}
	
	return ((desc_reverse_cnt == 1) and (v[n-1] > v[0])); 
}

bool checkAscending(vector<int> &v, int n)
{
	int asc_reverse_cnt = 0; 
	for(int i = 1; i < n; i++)
	{
		if(v[i-1] > v[i]){
			asc_reverse_cnt++; 
		}
	}
	
	return ((asc_reverse_cnt == 1) and (v[0] > v[n-1])); 
}

void solve()
{   
	// Do Something 
	int n; 
	cin >> n; 
	
	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 

	if((checkAscending(v, n)) or (checkDescending(v, n))){
		cout << "Yeah\n"; 
	}
		
	else 
		cout << "Nope\n"; 
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