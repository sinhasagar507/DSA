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
Details: The "rank" variable in the context of Disjoint Set data structure is used to keep 
		 track of the "rank" OR "depth" of each element in the set. The rank is an important
		 concept in optimizing the union operation in the union-find (disjoint set union) data structure 
		 
		 Here is how the "rank" variable is used: 
		 - Initialization: When each element is its own parent (in its own set), the rank of 
		 				   each element is set to 0 
		 				   
		 - Union By Rank: When performing the union operation between two sets represented by 
		 				  elements "u" and "v", the algorithm compares the ranks of the sets 
		 				  representatives ("ulp_u" and "ulp_v"). The goal is to merge the smaller 
		 				  rank set into the larger rank set. 
		 				  - If the rank of "ulp_u" is less than the rank of "ulp_v", then the parent of 
		 				  	"ulp_u" is set to "ulp_v"
		 				  - If the rank of "ulp_u" is greater than the rank of "ulp_v", then the parent of 
		 				    "ulp_v" is set to "ulp_u"
		 				  - If the ranks are equal, one set is chosen arbitrarily as the parent, 
		 				  	and the rank of the chosen parent is incremented 
		
*/
class DisjointSet {
	vector<int> rank, parent; 
	
	public: 
		DisjointSet(int n)
		{
			rank.resize(n+1, 0); 
			parent.resize(n+1); 
			
			for(int i = 0; i <= n; i++)
				parent[i] = i; 
			
		}
		
		// Find operation using path compression for efficient representative finding 
		int findUPar(int node) 
		{
			// If the node is its own parent, return the node 
			if(node == parent[node])
				return node; 
				
			// Perform path compression by recursively finding the parent 
			// and updating the parent of the current node to the ultimate parent 
			parent[node] = findUPar(parent[node]); 
			return parent[node]; 
		}
		
		// Union operation based on rank to optimize the merging of data 
		void unionByRank(int u, int v)
		{
			int ulp_u = findUPar(u); 
			int ulp_v = findUPar(v); 
			
			if(ulp_u == ulp_v)
				return; 
				
			if(rank[ulp_u] < rank[ulp_v])
				parent[ulp_u] = ulp_v; 
				
			else if(rank[ulp_u] > rank[ulp_v])
				parent[ulp_v] = ulp_u;
				
			else
			{
				parent[ulp_v] = ulp_u; 
				rank[ulp_u]++; 
			}
		
		}
}; 

int main()
{
	DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    
    else cout << "Not Same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    
    else cout << "Not Same\n";
    
    return 0;
}