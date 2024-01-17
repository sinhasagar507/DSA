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

int sortK(int arr[], int n, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq; 

	for(int i = 0; i <= k; i++)
		pq.push(arr[i]); 
		
	int index = 0; 
	for(int i = k+1; i < n; i++)
	{
		arr[index] = pq.top(); 
		pq.pop(); 
		pq.push(arr[i]); 
	}
	
	while(!pq.empty())
	{
		arr[index++] = pq.top(); 
		pq.pop(); 
	}
}

void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		cout << arr[i] << endl; 
		
	cout << endl; 
}

void solve()
{   
	// Do Something 
	int k = 3; 
	int arr[] = { 2, 6, 3, 12, 56, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	sortK(arr, n, k); 

	cout << "Following is sorted array" << endl; 
	printArray(arr, n); 
	
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