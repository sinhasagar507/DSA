/*
Kruskal's Algorithm: https://www.youtube.com/watch?v=DMnDM_sxVig


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
Algorithm 
	- Sort all the edges according to weight 
	- Define the set of edges alongwith their weights 
	- Sort all the edges by their weight 
	- Iterate through all edges, and check if the incoming edge is already a part of the subset of edges already processed OR it is a new one in itself
	- If its new one, then add its weight to the MSTWeight ELSE ignore 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The below class is already detailed in DSU sub-directory 
class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        parent[node] = findUPar(parent[node]);
        return parent[node];
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Added unionBySize method
    void unionBySize(int u, int v) {
        // Your implementation of unionBySize
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < V; i++) 
    {
        for (auto it : adj[i]) 
        {
            int node = i;
            int adjNode = it[0];
            int wt = it[1];

            edges.push_back({wt, {node, adjNode}});
        }
    }
    
    DisjointSet ds(V); 
    sort(edges.begin(), edges.end()); 
    int mstWeight = 0;
    
    for(auto it: edges)
    {
    	int wt = it.first; 
    	int u = it.second.first; 
    	int v = it.second.second; 
    	
    	if(ds.findUPar(u) != ds.findUPar(v))
    	{
    		mstWeight += wt; 
    		ds.unionByRank(u, v); // Union operation is a necessaity. Only that way I will be able to merge them AND keep a track of my path travelled 
    	}
    }
    
    return mstWeight;
}

void solve() {
    // Do Something
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0; // Corrected initialization

    while (i++ < E) {
        int u, v, w;
        cin >> u >> v >> w;

        vector<int> t1, t2;

        t1.push_back(v);
        t1.push_back(w);

        adj[u].push_back(t1);

        t2.push_back(u);
        t2.push_back(w);

        adj[v].push_back(t2);
    }

    cout << spanningTree(V, adj) << "\n "; // Removed extra space
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
