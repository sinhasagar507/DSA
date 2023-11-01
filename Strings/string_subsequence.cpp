/*
String Subsequence: Given two strings A and B, find if A is a subsequence of B. A subsequence is a sequence 
that can be derived from another sequence by deleting some elements without changing the order of the 
remaining elements
			 
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
	// Do Something
	string s, s1; 
	cin >> s >> s1; 
	
	int m = s.length(); 
	int n = s1.length();
	
	/* A loop to slide pattern[] one by one */
	// The following loop will run in both cases, whether characters in the pattern are distinct or repeated 
	
	// Time Complexity: O(m)
	for(int i = 0; i < m and j < n; i++ )
	{
		if(s1[i] == s2[j])
			j++;
		
	}
		 
	if(j == n)
		cout << "The subsequence exists" << endl; 
		
	else 
		cout << "The subsequence doesn't exist" << endl; 
}

/*
void solve{
// Recursive Code 
// Base Case
if(n == 0)
	return true; 
	
if(m == 0)
	return false; 
	
	
// Self Work and Recursive Intuition 
if(s1[m] == s2[n])
	return checkSubsequence(s1, s2, m-1, n-1); 
	
else
	return checkSubsequence(s1, s2, m-1, n);
}
*/


// Recursive Intuition 	

// Self Work 
 
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