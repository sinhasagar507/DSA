/* Program for Cycle Detection in Directed Acyclic Graphs (DAGs) using Kahn's BFS based algorithm */
#include<bits/stdc++.h> 
using namespace std; 

// Function to perform topological sorting and cycle detection using Kahn's algorithm
void topologicalSort(vector<int> adj[], int V) 
{ 
    // Initialize an array to keep track of in-degrees for each vertex
    vector<int> in_degree(V, 0); 
  
    // Calculate in-degrees for all vertices by traversing the adjacency list
    for (int u = 0; u < V; u++) { 
        for (int x : adj[u]) 
            in_degree[x]++; 
    } 
  
    // Initialize a queue for BFS traversal
    queue<int> q; 
    
    // Enqueue all vertices with in-degree 0 into the queue
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 

    int count = 0; // Initialize a count for processed vertices
    
    // Perform BFS traversal
    while (!q.empty()) { 
        int u = q.front(); 
        q.pop(); 
        
        // For each adjacent vertex, decrement its in-degree and enqueue if it becomes 0
        for (int x : adj[u]) 
            if (--in_degree[x] == 0) 
                q.push(x); 
        count++; // Increment the count of processed vertices
    } 
    
    // If the count of processed vertices is not equal to the total number of vertices,
    // there must be a cycle in the graph
    if (count != V) { 
        cout << "There exists a cycle in the graph\n"; 
    }
    else{
        cout << "There exists no cycle in the graph\n";
    }
}

// Function to add a directed edge from vertex u to vertex v in the adjacency list
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V = 5; // Number of vertices
	vector<int> adj[V]; // Create an array of vectors for adjacency list representation
    
	// Adding edges to create the directed graph
	addEdge(adj, 0, 1); 
    addEdge(adj, 4, 1); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 1);  
    
    // Perform topological sorting and cycle detection using Kahn's algorithm
    topologicalSort(adj, V);

	return 0; 
}