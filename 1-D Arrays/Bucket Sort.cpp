/*
Bucket Sort: https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Sorting/video/MTU1MQ%3D%3D
1. Consider a situation where we have numbers uniformly distributed in range from 1 to 10^8. How do we sort efficiently? 
2. Consider another situation where we have floating point numbers uniformly distributed in the range from 0.0 to 1.0 

The procedure consists of 3 steps:
1. First we scatter all the elements into individual buckets 
2. Thereafter, we sort the buckets 
3. Finally, we merge the sorted buckets into a single array  
Ideal Situation: n/k diviions 

I/P: arr[] = {20, 80, 10, 85, 75, 99, 18}
 K = 5 
 
Time Complexity: Assuming k ≈ n
Best Case: Data is uniformly distributed O(n)
Worst Case: All items go into a single bucket. If we use insertion sort on 
individual buckets, then O(n^2). I fwe use O(nlon) on individual buckets, then its O(nlogn). 
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
 
void solve()
{   
	int n, k;
	cin >> n >> k;
	vector<int> v(n); 
	vector<vector<int>> bucket(k); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 
		
	int max_val = v[0]; 
	for(int i = 1; i < n; i++)
		max_val = max(max_val, v[i]);

	
	// First we scatter all the elements into individual buckets  
	for(int i = 0; i < n; i++)
	{
		int bi = (k * v[i]) / max_val; 
		bucket[bi].push_back(v[i]); 
	} 
	
	// Sort individual buckets 
	for(int i = 0; i < k; i++)
		sort(bucket[i].begin(), bucket[i].end()); 
		
		
	// Merge all the buckets together 	
	int idx = 0; 
	for(int i = 0; i < k; i++)
		for(int j = 0; j < bucket[i].size(); j++)
			v[idx++] = bucket[i][j]; 
	
	for(int i = 0; i < n; i++)
		cout << v[i] << endl; 
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
 