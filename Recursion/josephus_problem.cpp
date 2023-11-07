/* 
Problem Statement: Maximum Circular Subarray Sum
Description: Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
			 A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
			 A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
I/P: arr[] = {5, -2, 3, 4}
O/P: 3+4+5 = 12
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

/* Recursive Approach 
Time Complexity: theta(n)
Space Complexity: theta(n)
*/ 

int jos(int n, int k) // Recurrence Relation: T(n) = T(n-1) + c 
{
	if(n == 1)
		return 0; 
		
	else 
		return (jos(n-1, k) + k) % n; 
}

int main()
{
	int n, k; 
	cin >> n >> k; 
	
	cout << jos(n, k) << endl; 

	return 0; 
}