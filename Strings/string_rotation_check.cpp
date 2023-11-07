/* 
Problem Statement: Given a string s1 and a string s2, write a snippet to 
                   say whether s2 is a rotation of s1? 
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



/*
Time Complexity of this approach: O(n^2)


*/
bool rotation_pattern_check(string s1, string s2) 
{
	int n1 = s1.length(); 
	int n2 = s2.length(); 
	
	if(n1 != n2)
		return false;  
	
	queue<char> q1, q2; 
	
	for(int i = 0; i < n1; i++)
	{
		q1.push(s1[i]); 
		q2.push(s2[i]); 
	}
	
	if(q1 == q2)
		return false; 
		
	for(int i = 0; i < n1; i++)
	{
		char elem = q2.front();
		q2.pop();  
		q2.push(elem);
		
		if(q1 == q2)
			return true;  
	}
	
	return false; 
}



void solve()
{   
	// Do Something 
	string s1, s2; 
	cin >> s1 >> s2;
	
	if(rotation_pattern_check(s1, s2))
		cout << "Yes, its a rotation" << endl; 
	else 
		cout << "No, its not a rotation" << endl; 
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