// Djikstra Algorithm for Shortest Path from a source vertex. Applicable for UWG 
/*
Some Key Points About this Algorithm
1. Doesn't work for negative edge weights and cycles 
2. Will work only for non-negative edge weights and cycles 
3. Does the shortest path change if we add a weight to all edges of a graph? Yes. Consider the graph: 
	A -> B(10) -> C(11) -> D(12) -> E(18) -> A(17)
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // Represents (node, weight) pair 
typedef long long int ll; 
#define INF INT_MAX 

struct Triple 
{ 
	int a, b, c; 
	 
	// Constructor
	Triple(int a, int b, int c)
	{
		this->a = a; 
		this->b = b; 
		this->c = c; 
	}
}; 

struct CustomComparator
{
	bool operator()(const Triple& x, const Triple& y){
		return x.a > y.a;
	}
};

vector<vector<pii>> graph;
priority_queue<Triple, vector<Triple>, CustomComparator> pq; 

vector<ll> findShortestPath(vector<bool> &visited, vector<ll> &dist, int src)
{	 
	while(!pq.empty())
	{
		Triple t1(pq.top()); 
		pq.pop();

		if(visited[t1.b] == true)
		continue;
		visited[t1.b] = true;  

		for(auto &pair: graph[t1.b])
		{
		
			int adj_node = pair.first; 
			int weight = pair.second; 
			
			if(visited[adj_node] == false)
			{
				pq.push(Triple(weight, adj_node, t1.b));
			
				if(dist[adj_node] > dist[t1.b] + weight)
					dist[adj_node] = dist[t1.b] + weight;  
			}
		}
	}
	
	return dist; 
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))
int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    graph.resize(numNodes);
    
    for(int i=0; i<numEdges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;  // Read an edge from user input ("from" node A "to" node B)
        graph[u].emplace_back(v, weight);  // Add the edge and corresponding weight to the adjacency list of 'u' node
        graph[v].emplace_back(u, weight);  // Add the edge and corresponding weight to the adjacency list of 'v' node
    }

    vector<bool> visited(numNodes, false);  // Create a boolean array to keep track of visited nodes 
    vector<ll> dist(numNodes, INF);  
    int src; 
    cin >> src; 
    dist[src] = 0; // Setting the distance of source vertex to 0 
    pq.push(Triple(0, src, -1)); // Push the distance, source node AND its corresponding parent into the priority queue 
    vector<ll> finalDist(numNodes); 
    
    finalDist = findShortestPath(visited, dist, src); 
    int i = 0; 
    cout << "Final Shortest Path Distances from source node\n"; 
    for(auto &dist: finalDist)
    {
		cout << i << " -> " << dist << endl; 
		i++; 
    }
    
    return 0;
}
