// Topological Sorting using DFS
// The time complexity of this algorithm is just as standard DFS algorithm: O(V+E)

#include<bits/stdc++.h>
using namespace std;

// Function which performs topological sorting using DFS
void DfsTopoSort(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &dfsStack, int src)
{
    visited[src] = true;  // Mark the current node as visited
    for(int u: graph[src])
    {
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

    vector<vector<int>> graph(numNodes);  // Create an empty adjacency list to represent the graph

    cout << "Enter the edges (format: u v) where u and v are nodes connected by an edge:\n";
    for(int i=0; i<numEdges; i++)
    {
        int u, v;
        cin >> u >> v;  // Read an edge from user input ("from" node A "to" node B)
        graph[u].push_back(v);  // Add the edge to the adjacency list of the 'u' node
    }

    vector<bool> visited(numNodes, false);  // Create a boolean array to keep track of visited nodes
    stack<int> dfsStack;  // A stack to store and pop nodes in a topological order

    cout << "Topological Sorting using DFS: ";

    for(int i=0; i<numNodes; i++)
    {
        if(visited[i] == false)  // If the current node hasn't been visited
            DfsTopoSort(graph, visited, dfsStack, i);  // Perform DFS-based topological sorting
    }

    while(!dfsStack.empty())
    {
        cout << dfsStack.top() << " ";  // Print the top node in the stack (topological order)
        dfsStack.pop();  // Pop the top node from the stack
    }

    return 0;
}
