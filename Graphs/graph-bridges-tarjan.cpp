/*
Refer the follwing video(s) for further revision: https://www.youtube.com/watch?v=qrAub5z8FeA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=55 AND https://www.youtube.com/watch?v=CiDPT1xM

*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
typedef long long int ll; 
#define INF INT_MAX 

vector<vector<int>> graph; 
vector<pii> bridges; 
int timer = 0; 

void findBridges(int node, int parent, vector<int> &tim, vector<int> &low, vector<bool> &visited) // Time Complexity is O(V+E)
{	 
	visited[node] = true; 
	tim[node] = low[node] = timer;  
	
	for(int adj_node: graph[node])
	{
		if(adj_node == parent)
			continue; 
			
		if(visited[adj_node] == false)
		{
			timer++; 
			findBridges(adj_node, node, tim, low, visited);
			 
			low[node] = min(low[node], low[adj_node]); 
			
			if(low[adj_node] > tim[node])
				bridges.push_back({node, adj_node}); 
		}
		
		else
			low[node] = min(low[node], low[adj_node]); 
		
	}
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))
int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    graph.resize(numNodes);
    
    for(int i=0; i<numEdges; i++)
    {
        int u, v;
        cin >> u >> v;  // Read an edge from user input 
        graph[u].emplace_back(v);  // Add the edge to the adjacency list of 'u' node
        graph[v].emplace_back(u);  // Add the edge to the adjacency list of 'v' node 
    }
    
    vector<int> tim(numNodes, -1); // Time of insertion via DFS algorithm 
    vector<int> low(numNodes, -1); // Minimum lowest time insertion of all adjacent nodes apart from parent 
    vector<int> parent(numNodes, -1); // For storing the parent node during DFS traversal 
    vector<bool> visited(numNodes, false); 
    
    findBridges(0, -1, tim, low, visited); 
    
    for(auto &pair: bridges)
    	cout << pair.first << " <-> " << pair.second << endl; 

    return 0;
}