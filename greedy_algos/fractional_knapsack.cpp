/*
Problem Statement: Given the weights and values of N items, put these items in a knapsack of 
capacity W to get the maximum total value in the knapsack. In Fractional Knapsack, we can break items 
for maximizing the total value of the knapsack
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

struct Item {
	int value; 
	int weight;
	
	Item(int v, int w) : value(v), weight(w) {} 
}; 

// Custom comparator function to compare two items based on their value-to-widget ratio 
bool compareItems(const Item &a, const Item &b)
{
	return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight); 
}

// Main greedy function to solve Knapsack problem 
double fractionalKnapsack(int W, vector<Item> &v1) // Max Time Complexity: O(nlogn)
{
	// Sorting items based on the ratio of value to weight 
	sort(v1.begin(), v1.end(), compareItems); 
	
	// Result (value in the Knapsack)
	double finalVal = 0.0; 
	
	// Loop through all items 
	for(const Item &item: v1)
	{
		// If adding the item won't overflow, add it completely 
		if(item.weight <= W) {
			W -= item.weight; 
			finalVal += item.value; 
		}
		
		else {
			// If we can't add the current item completely, add a fractional part of it 
			finalVal += item.value * W / static_cast<double>(item.weight); 
			break; 
		}
	}
	
	// Return final value 
	return finalVal; 
}

void solve()
{   
	// Do Something 
	// Provide the weight of the knapsack W 
	// Provide the no of items in the other bag 
	
	int W, N; 
	cin >> W >> N; 
	
	vector<Item> v1; 
	for(int i = 0; i < N; i++)
	{
		int val, wei; 
		cin >> val >> wei; 
		v1.push_back(Item(val, wei)); 
	}
	
	cout << fractionalKnapsack(W, v1) << endl; 
	
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