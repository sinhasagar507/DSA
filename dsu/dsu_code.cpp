/*
Problem Statement: 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
const int CHAR = 256; 
 
template <class T>
	ll giveNcR(ll n, ll r){ll p = 1, k = 1; if(n-r < r) r = n - r; if(r != 0){while(r) {p *=n; k *=r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; 
	return p;}
	
 
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
int no_of_digits(ll n){return 1 + floor(log10(n));}
 
// vector<int> graph[N];
bool visited[N+1];
int dist[N+1];
int source[N+1];
queue<int> node_queue;
vector<int> parent(N, -1);

struct Graph
{
	int src; 
	int dest; 
	
	// Constructor
	Graph() : src(0), dest(0){} // Default constructor

	Graph(int src, int dest)
	{
		this->src = src; 
		this->dest = dest; 
	}
}; 

vector<Graph> v; 


// Find the representative of the set 
// that i is an element of 
int find(int i)
{
	// If i is the parent of itself 
	if(parent[i] == -1)
		// Then i is the representation of 
		// this set 	
		return i; 
		
	else 
	{
		// Else if i is not the parent of 
		// itself, then i is not the 
		// representative of this set. So 
		// we recursively call Find() on 
		// its parent
		return find(parent[i]); 
	}
}

// Unites the set that includes i 
// and the set that includes j 
void unionSet(int i, int j)
{
	// Find the representatibes of the 
	// (or the root nodes) for the set 
	// that includes i 
	int irep = find(i); 
	
	// And do the same for the set 
	// that includes j 
	int jrep = find(j); 
	
	// Make the parent of j's representative 
	// be i's representative effectively 
	// moving all of j's set into i's set)
	parent[jrep] = irep; 
}

// The main function to check whether a given graph contains 
// cycle or not 
int isCycle()
{
	// Iterate through all edges of a graph, find subset of both 
	// vertices of every edge, if both subsets are same, then 
	// there is cycle in graph
	int graph_size = v.size();  
	for(int i = 0; i < graph_size; i++)
	{
		int x = find(v[i].src); 
		int y = find(v[i].dest); 
		
		if(x == y)
			return 1; 
			
		unionSet(x, y); 
	}
	
	return 0; 
	
}

void solve() 
{   
	// Do Something
	// Enter the no of edges in the graph
	int n; 
	cin >> n; 
	
	for(int i = 0; i < n; i++)
	{
		int node1, node2; // List the nodes 
		cin >> node1 >> node2; 
		v.push_back(Graph(node1, node2));  
	}
	
	if(isCycle())
		cout << "Graph contains cycle"; 
		
	else 
		cout << "Graph doesn't contain cycle"; 
		
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