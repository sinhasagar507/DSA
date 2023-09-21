/*
Problem Statement: Largest Element in an Array
Time Complexity: O(n)
Space Complexity: O(1)
*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e5 + 5;
const ll N1 = 3 * 1e6;
const ll N2 = 1e9 + 7;

template <class T>
	ll giveNcR(ll n, ll r){ll p = 1, k = 1; if(n-r < r) r = n - r; if(r != 0){while(r) {p *=n; k *=r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; 
	return p;}
	
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
int no_of_digits(ll n){return 1 + floor(log10(n));}

int n;
int a, b, c, d;
bool f = false;

/*Brute Force Method 
	Equivalent as efficient approach 
*/

int main()
{
	int n; 
	cin >> n; 
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];  
	}
	
	int maxElement = *max_element(v.begin(), v.end()); 
	cout <<  maxElement << endl;
	return 0; 
}
