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

bool find_subsequence(vector<int> &v, int target, int curr_sum, int index, vector<int> &result)
{
	if(curr_sum == target)
	{
		cout << "Susbequence found: " << "\U0001F600\n"; 
		return true; 
	}
	
	if(index == v.size() or curr_sum > target) 
		return false; // Terminate recursion 
		
	// Include the current element in the subsequence 
	result.push_back(v[index]); 
	if (find_subsequence(v, target, curr_sum+v[index], index+1, result))
		return true; // Terminate 
	
	// Exclude the current element from the subsequence 
	result.pop_back(); 
	return find_subsequence(v, target, curr_sum, index+1, result); 
}

void solve()
{   
	 // Do Something
	 vector<int> v = {3, 4, 7, 4, 6};
	 vector<int> result;  
	 
	 if(find_subsequence(v, 12, 0, 0, result))
	 	cout << "Oh Yeah!!!" << "\n"; 
	 	
	 else 
	 	cout << "Nope, subsequence not found " << "\U0001F61E\n";
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