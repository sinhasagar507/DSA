/*
Problem Statement: Shortest distances of vertices from a given node to all other nodes 

Advantages of BFS for this algorithm: 
1. Simplicity and efficiency: BFS is straightforward to implement and understand 
2. Unweighted Graph Approximation: When edge weights are close or equivalent across the graph, 
								   BFS might approximate the shortest path approximately well 
3. Space Complexity: BFS usually has lower time complexity as compared to other algorithms, so its good enough 


Disadvantages: 
1. Can't be used for shortest path in weighted graphs. Reasons being node by node exploration without considering varying edge weights. 
2. Optimality Guaranetee: BFS doesn't guarantee the optimal shortest path in weighted graphs because it might select paths with more edges
						  but lower cumulative weights, which isn't necesarrily the shortest path based on weight 
3. Failure to Consider Weight Differences: In weighted graphs, edges may have different weights, indicating different costs or distances between 
										   nodes. BFS does not account for these weight differences.  
4. Routing Algorihms: BFS aids in finding the shortest path 
*/

#include<bits/stdc++.h> 
using namespace std; 

void BFS(vector<int> adj[], int V, int s, int dist[]) 
{ 
	bool visited[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	queue<int>  q;
	
	visited[s] = true; 
	q.push(s); 

	while(q.empty()==false) 
	{ 
		int u = q.front(); 
		q.pop();
		 
		for(int v:adj[u]){
		    if(visited[v]==false){
		        dist[v]=dist[u]+1;
		        visited[v]=true;
		        q.push(v);
		    }
		} 
	} 
} 

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=4;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,0,2); 
	addEdge(adj,1,3);
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
	dist[0]=0;
	BFS(adj,V,0,dist); 
    
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }

	return 0; 
} 
