/*
Problem Statement: Find median in a row-wise sorted array. 
We are given a row-wise sorted matrix of size r*c, 
we need to find the median of the matrix given. It is assumed that r*c is always odd. 

Input : 1 3 5
        2 6 9
        3 6 9
Output : Median is 5
If we put all the values in a sorted 
array A[] = 1 2 3 3 5 6 6 9 9)

Input: 1 3 4
       2 5 6
       7 8 9
Output: Median is 5
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
const int MAX = 100; 
 
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


// Time Complexity of this algorithm: O(max(r, c)). Auxiliary Space Complexity: O(1)
int binaryMedian(int m[][MAX], int r, int c)
{
	int mini = INT_MAX, maxi = INT_MIN; 
	
	// Minimum element will be found in the first column 
	for(int i = 0; i < r; i++)
		mini = min(mini, m[i][0]); 
		
	// Maximum element will be found in the last column 
	for(int i = 0; i < r; i++)
		maxi = max(maxi, m[i][c-1]); 
	
	// After obtaining the minimum and maximum values, we can assume the median to be 
	int desired = (r * c + 1) / 2; 
	
	while(mini < maxi)
	{
		int place = 0; 
		int mid = mini + (maxi - mini) / 2; // Performing this operation reduces the chances of overflow 
		
		for(int i = 0; i < r; i++) // Through this for loop we are calculating the upper bound for "mid" in each of the rows. Accumulate no. of elements in each row which are lesser than mid 
			place += upper_bound(m[i], m[i] + c, mid) - m[i]; // m[i] returns the pointer to the first element of thew sub array 
			
		if(place < desired)
			mini = mid + 1; 
			
		else 
			maxi = mid;  	
	}
	
	return mini;
}

int main()
{	
	int r = 3, c = 3; 
	int m[][MAX] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}}; 
	cout << "Median is: " << binaryMedian(m, r, c) << endl; 
	return 0; 
}