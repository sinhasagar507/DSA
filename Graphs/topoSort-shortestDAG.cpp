// Topological Sorting based Shortest Path algorithm
// The time complexity of this algorithm is just as standard DFS algorithm: O(V+E)

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
#define INF INT_MAX 

// Function which performs topological sorting using DFS
void DfsTopoSort(vector<vector<pii>> &graph, vector<bool> &visited, stack<int> &dfsStack, int src)
{
    visited[src] = true;  // Mark the current node as visited
    for(auto &pair: graph[src])
    {
        int u = pair.first; 
        if(visited[u] == false)  // If the neighbor node hasn't been visited
            DfsTopoSort(graph, visited, dfsStack, u);  // Recursively perform DFS on unvisited neighbors
    }

    dfsStack.push(src);  // Push the current node onto the stack
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges in the graph: ";
    cin >> numNodes >> numEdges;

    vector<vector<pii>> graph(numNodes);  // Create an empty adjacency list to represent the graph

    cout << "Enter the edges (format: u v) where u and v are nodes connected by an edge, alongwith the edge weight: \n";
    for(int i=0; i<numEdges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;  // Read an edge from user input ("from" node A "to" node B)
        graph[u].emplace_back(v, weight);  // Add the edge to the adjacency list of the 'u' node
    }

    vector<bool> visited(numNodes, false);  // Create a boolean array to keep track of visited nodes
    stack<int> dfsStack;  // A stack to store and pop nodes in a topological order
    vector<long> dist(numNodes, INF); // Stores the minimum distances from one node to all other nodes of the array 

    cout << "Topological Sorting using DFS: ";

    for(int i=0; i<numNodes; i++)
    {
        if(visited[i] == false)  // If the current node hasn't been visited
            DfsTopoSort(graph, visited, dfsStack, i);  // Perform DFS-based topological sorting
    }
    
    cout << "Enter the source node for calculating distances:\n"; 
    int node; cin >> node; 
    dist[node] = 0; // Since it is the source vertex, we set its distance to 0 

    while(!dfsStack.empty())
    {
        int node = dfsStack.top();  // Print the top node in the stack (topological order)
        for(auto &pair: graph[node])
            dist[pair.first] = min(dist[pair.first], dist[node] + pair.second); 
        
        dfsStack.pop();  // Pop the top node from the stack
    }
    
    for(int i=0; i<numNodes; i++)
        cout << dist[i] << " "; 
    cout << endl; 

    return 0;
}
