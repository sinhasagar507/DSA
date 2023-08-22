// The current algorithm will work only for undirected graphs

#include <bits/stdc++.h> 
using namespace std; 

// function to perform BFS traversal on a graph 
void BFS(vector<vector<int>> &graph, int src)
{
    int numNodes = graph.size(); 
    vector<bool> visited(numNodes, false); 
    
    // Create a queue for BFS 
    queue<int> q; 
    
    // Mark the source node as visited and enqueue it 
    visited[src] = true; 
    q.push(src); 
    
    while(!q.empty())
    {
        // Deque a vertex from the queue and print it 
        int curr = q.front(); 
        q.pop(); 
        cout << curr << " "; 
        
        // Get all adjacent vertices of the dequeued vertex current 
        // If an adjacent vertex hasn't been visited, mark it as visited and enqueue it 
        for(int neighbor: graph[curr])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true; 
                q.push(neighbor); 
            }
        }
    }
}

int main()
{
    int numNodes, numEdges; 
    cout << "Enter the number of nodes and edges in the graph: "; 
    cin >> numNodes >> numEdges; 
    
    vector<vector<int>> graph(numNodes); 
    
    cout << "Enter the edges (format: u v) where u and v are nodes connected by an edge:\n";
    for(int i=0; i<numEdges; i++)
    {
        int u, v; 
        cin>>u>>v; 
        graph[u].push_back(v); 
        graph[v].push_back(u); 
    }
    
    int src; 
    cout << "Enter the source node for BFS traversal: "; 
    cin >> src; 
    
    cout << "BFS Traversal: "; 
    BFS(graph, src); 
    
    return 0; 
    
}