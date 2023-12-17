/*
Problem Statement: Breadth First Search (BFS) for a graph 

Corner Cases: 
1. Disconnected Graphs: Two disconnected components: {0, 1, 2} and {3, 4}
2. Single Node or Self Loop: graph[0] = {0};
3. Empty Graph: No Graph 
4. Directed Acylic Graph
	    graph[0] = {1, 2};
    	graph[1] = {3};
    	graph[2] = {4};
    	graph[3] = {5};
    	graph[4] = {5};
    	graph[5] = {};
5. Cyclic Graph with a Cycle 
		// Cyclic graph with a cycle: 0 -> 1 -> 2 -> 0
       graph[0] = {1};
       graph[1] = {2};
       graph[2] = {0};
       graph[3] = {}; 
       
       
Applications 
1. Graph Traversal
	- Shortest Path and Pathfinding: Can determine the shortest path between two nodes in an unweighted graph
	  Used in GPS systems, route planning and navigation maps
	- Web Crawling: Used by search engines to index web pages  
2. Network Analysis 
	- Analyzing social networks, finding connections, or determining degrees of separation between individuals 
	- Network Routing and BroadCast: In CNs, BFS aids in broadcasting messages or routing packets efficiently 
3. Puzzles and Games 
	- Maze Solving 
	- Game AI 
*/

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