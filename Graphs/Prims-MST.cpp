// Prim's Algorithm for MST 
// : O(V+E)

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
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

int findMST(vector<vector<pii>> &graph, priority_queue<Triple, vector<Triple>, CustomComparator> &pq, vector<bool> &visited, vector<pii> &MST, int src)
{	 
	int edge_sum=0; 
	while(!pq.empty())
	{
		Triple t1(pq.top()); 
		pq.pop(); // log E  
		
		// This is my code and it works okay fine
		// But a suggested improvement here would be 
		
		cout << t1.a << " " << t1.b << " " << t1.c << endl; 
		if(visited[t1.b]==true)
			continue; 
				
		if(t1.b!=src) 
		{
			MST.push_back({t1.b, t1.c}); 
			edge_sum += t1.a;
		}
		
		visited[t1.b] = true;

		for(auto &pair: graph[t1.b]) // E
		{
			if(visited[pair.first]==false)
				pq.push(Triple(pair.second, pair.first, t1.b)); // log E 
		}
	}
	
	return edge_sum; 
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges in the graph: ";
    cin >> numNodes >> numEdges;

    vector<vector<pii>> graph(numNodes);   // Create an empty adjacency list to represent the graph. It can also be defined as a 2D vector<vector<int>> 
	priority_queue<Triple, vector<Triple>, CustomComparator> pq;
	

    cout << "Enter the edges (format: u v) where u and v are nodes connected by an edge, alongwith the edge weight: \n";
    for(int i=0; i<numEdges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;  // Read an edge from user input ("from" node A "to" node B)
        graph[u].emplace_back(v, weight);  // Add the edge and corresponding weight to the adjacency list of 'u' node
        graph[v].emplace_back(u, weight);  // Add the edge and corresponding weight to the adjacency list of 'v' node
    }

    vector<bool> visited(numNodes, false);  // Create a boolean array to keep track of visited nodes 
    vector<pii> MST; // cannot initialize the size in the beginning since the total no. of nodes is unknown 
    
    cout << "Enter the starting node for your MST: " << " "; 
    int src; 
    cin >> src; 
    cout << endl; 
    pq.push(Triple(0, src, -1)); // Push the edge weight, source node AND the corresponding parent into the priority queue 
    
    cout << findMST(graph, pq, visited, MST, src) << endl; 
    
    for(auto &pair: MST)
    	cout << pair.first << " -> " << pair.second << endl; 
    	
    return 0;
}
