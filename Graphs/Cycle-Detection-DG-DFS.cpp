// Detect cycles in a directed graph 
// The time complexity of this algorithm is just as standard DFS algorithm: O(V+E)

#include<bits/stdc++.h> 
using namespace std; 

// Function to perform depth-first search recursively to detect cycles in a directed graph
bool DFSRec(vector<vector<int>> &graph, int curr_node, vector<bool> &visited, vector<bool> &recTree)
{
    // Mark the current node as visited and add it to the recursion stack
    visited[curr_node] = true; 
    recTree[curr_node] = true; 
    
    // Traverse all adjacent nodes of the current node
    for(int adj_node: graph[curr_node])
    {
        // If the adjacent node is not visited yet, perform DFS on it
        if(!visited[adj_node])
        {
            visited[adj_node] = true; 
            DFSRec(graph, adj_node, visited, recTree); 
        }
        
        // If the adjacent node is already in the recursion stack, a cycle is detected
        // Return true to indicate the presence of a cycle
        if(recTree[adj_node])
            return true; 
    }
    
    // Remove the current node from the recursion stack as we move back in the recursion
    recTree[curr_node] = false; 
    
    // No cycle is detected, return false
    return false; 
}

// Function to perform depth-first search on all unvisited nodes to detect cycles in a directed graph
bool DFS(vector<vector<int>> &graph, int numNodes, vector<bool> &visited, vector<bool> &recTree)
{
    // Loop through all nodes in the graph
    for(int i=0; i<numNodes; i++)
    {
        // If the current node is unvisited, perform DFS starting from that node
        if(visited[i] == false)
        {
            // If a cycle is detected in the DFS, return true
            if(DFSRec(graph, i, visited, recTree))
                return true; 
        }
    }
    
    // If no cycle is detected after exploring all nodes, return false
    return false; 
}

int main()
{
    int numNodes, numEdges; 
    cout << "Enter the number of nodes and edges in the graph: "; 
    cin >> numNodes >> numEdges; 
    
    vector<vector<int>> graph(numNodes); // Create an empty adjacency list to represent the graph
    
    cout << "Enter the edges (format: u v) where u and v are nodes connected by an edge:\n";
    for(int i=0; i<numEdges; i++)
    {
        int u, v; 
        cin>>u>>v; // Read an edge from user input ("from" node A "to" node B)
        graph[u].push_back(v); // Add the edge to the adjacency list of the 'u' node
    }
    
    vector<bool> visited(numNodes, false); // Create a boolean array to keep track of all visited nodes
    vector<bool> recTree(numNodes, false); // Create a boolean array to keep track of potential cycle nodes
    
    cout << "Cycle Detection in Directed Graph: ";
    
    // Check if a cycle exists in the graph using the DFS function
    if(DFS(graph, numNodes, visited, recTree))
        cout << "Yes, cycle exists" << endl; 
    else 
        cout << "No, cycle doesn't exist" << endl; 
    
    return 0; 
}
