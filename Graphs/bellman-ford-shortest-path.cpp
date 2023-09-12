/*
Important Characteristics of Bellman Ford Algorithm 
1. Helps us to detect negative cycles in a graph, which otherwise would encounter a TLE using Djikstra algorithm 
2. Works with negative-valued edges as well 
3. Its a DP-based solution solution 
4. Applicable only for DG. If I want it to work for undirected weighted graphs, I need to represent the graph as a directed graph
5. In this algorithm, we relax all the edges (N-1) times sequentially. The edge relaxation follows from Djikstra algorithm 
6. Intuition behind (N-1) relaxations: 5 nodes, 4 edges, 0->1(1)->2(1)->3(1)->4(1)

Some disadvantages of Shortest Path Algorithm 
1. Time Complexity: The Bellman-Ford algorithm has a time complexity of O(V * E), where V is the number of vertices and E is the number of edges. This makes it less efficient than Dijkstra's algorithm, which has a better time complexity of O((V + E) * log V) using priority queues
2. Negative Cycles: The algorithm is susceptible to negative weight cycles. If a negative weight cycle exists in the graph reachable from the source vertex, the algorithm will not provide correct results. In such cases, the algorithm can be used to detect negative cycles, but the shortest path values won't be meaningful
3. Multiple Iterations: The algorithm requires multiple iterations through all edges for V - 1 times, even when the shortest paths have already been found. This can make it inefficient for graphs where most paths are already optimal
4. Performance on Sparse Graphs: In comparison to Dijkstra's algorithm, which is particularly efficient for sparse graphs, the Bellman-Ford algorithm's time complexity makes it less suitable for such cases
5. No Negative Cycles: If the graph doesn't contain any negative weight cycles, the algorithm's repeated iterations can be inefficient. It's an overkill when the shortest paths are already established in fewer iterations
6. Edge Relaxation Count: The number of times the edges need to be relaxed may vary based on the order in which the vertices are processed. This introduces some non-determinism into the process
7. Not Suitable for Some Applications: The algorithm might not be the best choice when negative weights are rare, and the graph is mostly non-negative. In such cases, Dijkstra's algorithm is generally more efficient 
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
typedef long long int ll; 
#define INF INT_MAX 

struct Triple 
{ 
	int u, v, weight; 
	 
	// Constructor
	Triple() : u(0), v(0), weight(0) {} // Default constructor

	Triple(int u, int v, int weight)
	{
		this->u = u; 
		this->v = v; 
		this->weight = weight; 
	}
};

vector<vector<pii>> graph; 
vector<Triple> edgelst; 

void findShortestPath(vector<ll> &dist, int src, int numNodes) // Time Complexity is O(VE)
{	 
	for(int i=0; i<numNodes-1; i++)
	{
		for(auto &edge: edgelst)
		{
			int parent = edge.u; 
			int child = edge.v; 
			int weight = edge.weight; 
			
			if(dist[child] > dist[parent] + weight)
				dist[child] = dist[parent] + weight; 
		}
	}
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))
int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    graph.resize(numNodes);
    edgelst.resize(numEdges); 
    
    for(int i=0; i<numEdges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;  // Read an edge from user input ("from" node A "to" node B)
        graph[u].emplace_back(v, weight);  // Add the edge and corresponding weight to the adjacency list of 'u' node
        edgelst.emplace_back(Triple(u, v, weight)); // Creating a vector of edges and corresponding weights, which makes it easy for further calculations 
    }
    
    vector<ll> dist(numNodes, INF);  
    int src; 
    cin >> src; 
    dist[src] = 0; // Setting the distance of source vertex to 0 
    vector<ll> finalDist(numNodes); 
    
    findShortestPath(dist, src, numNodes); 
    int i = 0; 
    for(auto distance: dist)
    {
		cout << i << " -> " << distance << endl; 
		i++; 
    }
    
    return 0;
}
