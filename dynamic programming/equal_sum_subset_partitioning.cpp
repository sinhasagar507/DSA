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


/*
This code checks for subsequence sum 
bool f(vector<int>& v, unordered_set<int>& us, int n, int i, int sum) 
{
    // Base Case(s)
    if (i == n-1) {
        if (us.find(sum) != us.end()) {
            return true; // Sum found in the set
        } else {
            us.insert(sum); // Insert the sum into the set
            return false; // Sum not found
        }
    }

    // Recursive Intuition
    bool lsum = f(v, us, n, i + 1, sum); // Exclude current element 
    bool rsum = f(v, us, n, i + 1, sum + v[i]); // Include current element

    // Self Work
    return (lsum or rsum); // Return based on the recursive checks
}
*/

// The following code checks for substring sum 
// Check why this code ain't working 
bool f(vector<int> &v, int n, int i, int sum1, int sum2)
{
	if(i == n-1)
		return (sum1 == sum2); // Check if both sums are equal 
		
	// Recursive Intuition 
	// Two Options: include v[i] in the first subset or the second subset 
	bool subset1 = f(v, n, i+1, sum1+v[i], sum2); 
	bool subset2 = f(v, n, i+1, sum1, sum2+v[i]); 
	
	// Return true if any of the recursive calls finds equal partitioning 
	return (subset1 or subset2); 
}

// Check why th
bool f(vector<int>& v, int n, int k)
{
	
	// Since I have a 2D DP array, I can space optimize it to a 1D array 
	vector<bool> prev(k+1, false), curr(k+1, false); 
	
	// Base Cases 
	// In whatever index the target becomes 0, return true
 
	prev[0] = true; 
	curr[0] = true; 
	
	// In the 0th index, only for all those targets where target has reduced to a[0], return true 
	prev[v[0]] = true; 
	
	// Now convert the states to loops 
	for(int i = 1; i < n; i++)
	{
	// Target is a desired sum...Now since I am building it from bottom up...kahin pe kmm value hoga 
		for(int target = 1; target <= k; target++)
		{
			bool notTake = prev[target]; 
			bool take = false;
			
			if(target-v[i] >= 0)
				take = prev[target-v[i]];
				
			curr[target] = take or notTake; 
			
		}
		
		prev = curr; 
	}

	return prev[k]; 
}


void solve()
{   
	// Do Something
	int n, sum = 0; 
	cin >> n; 
	
	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i]; 
	}
	
	if(sum%2)
		cout << "0" << endl; 
	
	else 
		cout << f(v, n, sum/2) << endl; 
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