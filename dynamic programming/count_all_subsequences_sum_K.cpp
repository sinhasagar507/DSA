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
int mod = 1e9 + 7; 

int f(vector<int>& v, int n, int k)
{
	vector<vector<int>> table(n, vector<int>(k+1));
	
	// for(int i = 0; i < n; i++)
		// table[i][0] = 1; 
// 		
	// table[0][v[0]] = 1; 

	for(int i = 0; i < n; i++)
	{
		for(int target = 0; target <= k; target++)
		{
			// if(i == 0 and target == 0 and v[0] == 0)
				// table[i][target] = 2;  
			// else if(i == 0 and target == v[0] and v[0] != 0)
				// table[i][target] = 1; 
			// if(i != 0 and target == 0)
				// table[i][target] = 1; 
			// else 
			// {
				int notPick = table[i-1][target];
				int pick = 0; 

				if((target - v[i]) >= 0)
					pick = table[i-1][target-v[i]]; 
	
				table[i][target] = (pick + notPick)%mod; 
			// }
		}
	}

	return table[n-1][k]; 
}

int findWays(vector<int>& v, int n, int k)
{
	// Write your code here.
	// Here each dp cell will contain a sum <= k 
	// but tot_sum - something(v[i]) >= k...
	// Why do I tend to complicate things???
	// Since indexing starts from 1 in the original array and 0<=calculated_sum<=k
	// vector<vector<int>> dp(n, vector<int>(k+1, -1));

	// return f(arr, dp, k, n-1);  
	return f(v, n, k); 
}

void solve()
{   
	// Do Something 
	int n, k; 
	cin >> n >> k; 
	
	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 
		
	cout << findWays(v, n, k) << endl; 
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