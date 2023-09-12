// The following algorithm finds strongly connected components using Kosaraju's algorithm 
// Refer this video for further details during revision: https://www.youtube.com/watch?v=R6uoSjZ2imo

/*
Some Important Notes about this algorithm 
1. Applicable for Directed Graphs only 

2. Algorithm 
a. Order the vertices in decreasing order of finish times in DFS 
b. Reverse all edges - Reverse all edges 
c. Do DFS of the reversed graph in the order obtained in step 1. For every vertex, print all reachable vertices as one strongly connected component 

*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
typedef long long int ll; 
#define INF INT_MAX 
vector<vector<int>> graph;
vector<vector<int>> reversedGraph;
stack<int> st; // A queue for storing all nodes according to their finishing time
int comps = 0;  

void dfs1(int node, vector<bool> &visited)
{	 
	visited[node] = true;  
	
	for(int adj_node: graph[node])
	{
		if(!visited[adj_node])
			dfs1(adj_node, visited); 
	}
	st.push(node); 
}

void graphReverse(int numNodes)
{
	for(int i=0; i<numNodes; i++)
	{
		for(int adj_node: graph[i])
			reversedGraph[adj_node].push_back(i); 
	}
}

void dfs2(int node, vector<bool> &visited) // 
{
	visited[node] = true; 
	
	for(int adj_node: reversedGraph[node])
	{
		if(!visited[adj_node])
			dfs2(adj_node, visited); 
	}
}

void calculateComponents(vector<bool> &visited)
{
	while(!st.empty())
	{
		int node = st.top();
		st.pop();
		
		if(visited[node] == true)
			continue; 
		
		dfs2(node, visited); 
		comps++; 
	}
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))
int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    graph.resize(numNodes);
    reversedGraph.resize(numNodes); 
    
    for(int i=0; i<numEdges; i++)
    {
        int u, v;
        cin >> u >> v;  // Read an edge from user input ("from" node A "to" node B)
        graph[u].push_back(v);  // Add the edge and corresponding weight to the adjacency list of 'u' node
    }

    vector<bool> visited(numNodes, false);  // Create a boolean array to keep track of visited nodes
    for(int i=0; i<numNodes; i++)
    {
    	if(!visited[i])
    		dfs1(i, visited);
    }
    
    fill(visited.begin(), visited.end(), false);
    graphReverse(numNodes); 
    calculateComponents(visited); 
    
    cout << comps << endl; 
    return 0;
}
