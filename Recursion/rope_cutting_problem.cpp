/*
Problem Statement: Given a rope of length N meters, and the rope can be cut in only 3 sizes A, B 
				   and C. The task is to maximize the no. of cuts in the rope. If it is possible to
				   make the cut then print the number else print -1. 
				   
Sample Test Cases for Dry Run: 
Input: 
N = 17, A = 10, B = 11, C = 3 
Output: 3 
Explanation: The maximum cut can be obtain after making 2 cut of length 3 and one cut of length 11. 

Input: N = 10, A = 9, B = 7, C = 11 
Output: -1 
Explanation: It is impossible to make any cut so output will be -1.
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

int maxCnts(int n, int a, int b, int c) // Time Complexity is O(3^n)
{
    // Base case: If 'n' is already 0, no further counts are needed
    if (n == 0)
        return 0;

    // Base case: If 'n' is negative, it is not possible to represent 'n'
    if (n <= -1)
        return -1;

    // Recursive case: Calculate the maximum counts by trying all possibilities
    // Recursive formula: maxCnts(n, a, b, c) = 1 + max(maxCnts(n-a, a, b, c), maxCnts(n-b, a, b, c), maxCnts(n-c, a, b, c))
    int res = max(maxCnts(n - a, a, b, c),
                  max(maxCnts(n - b, a, b, c), maxCnts(n - c, a, b, c)));

    // If it is not possible to represent 'n' using 'a', 'b', and 'c', set result to -1
    if (res == -1)
        return -1;

    // Increment the result by 1 to account for the current count
    else
        return res + 1;
}


void solve()
{   
	// Do Something 
	int n, a, b, c; 
	cin >> n >> a >> b >> c; 
	
	cout << maxCnts(n, a, b, c) << "\n"; 

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