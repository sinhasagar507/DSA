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

/*Brute Force Method 
int maxCircularSum(vector<int> v, int n)
{
	int res = v[0]; 
	for(int i = 0; i < n; i++)
	{
		int curr_max = v[i]; 
		int curr_sum = v[i]; 
		
		for(int j = 1; j < n; j++)
		{
			int idx = (i + j) % n; 
			curr_sum += v[idx]; 
			curr_max = max(curr_max, curr_sum)
		}
		
		res = max(res, curr_max); 
	}
	
	return res; 
}

Time Complexity: theta(n^2)
Space Complexity: theta(1)
*/

// Function to find the smallest sum contiguous subarray
int findMinimumSum(vector<int> &v, int n)
{
	// to store the minimum value that is ending
	// up to the current index
	int min_ending_here = INT_MAX;
	
	// to store the minimum value encountered so far
	int min_so_far = INT_MAX;
	
	// traverse the array elements
	for (int i=0; i<n; i++)
	{
		// if min_ending_here > 0, then it could not possibly
		// contribute to the minimum sum further
		if (min_ending_here > 0)
			min_ending_here = v[i];
		
		// else add the value arr[i] to min_ending_here
		else
			min_ending_here += v[i];
		
		// update min_so_far
		min_so_far = min(min_so_far, min_ending_here);		
	}
	
	// required smallest sum contiguous subarray value
	return min_so_far;
}

int maxSum(vector<int> &v, int n)
{
	int res = v[0], maxEnding = v[0]; 
	for(int i = 1; i < n; i++){
		maxEnding = max(v[i], maxEnding + v[i]);
		res = max(res, maxEnding); 
	}
	
	return res; 
}

int main()
{
	int n, tot_sum = 0; 
	cin >> n; 
	
	vector<int> v(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i]; 
		tot_sum += v[i]; 
	}
	
	int normalMaxSum = maxSum(v, n); 
	int minSum = findMinimumSum(v, n); 
	
	cout << ((normalMaxSum > 0) ? max(normalMaxSum, tot_sum - minSum) : normalMaxSum) << endl;
	return 0; 
}