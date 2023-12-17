// Topological Sorting using DFS
// The time complexity of this algorithm is just as standard DFS algorithm: O(V+E)

// Definition: Linear Ordering of vertices such that if there is an edge between u and v, u appears before v in that ordering. 

// Corner Case for testing: 5 -> 0, 4 -> 0, 4 -> 1, 5 -> 2, 2 -> 3, 3 -> 1

/*




Limitations of topological sort: 
1. It only works for DAG's and cannot handle cyclic graphs 
2. It may not be the e


Applications: 
1. Task Scheduling: In project management and task scheduling, topo sort helps determine the 
                    optimal sort of tasks with dependencies
2. Library Dependency: One depends on another...All of them depend on Python3 for installation 
					   For Torch installation: Python, NumPy, CMake, Pip, CUDA Toolkit, etc. are 
					   required
3. Build Systems: Systems such as Make, CMake, or Ant, are used in software development to automate 
				  the process of building software from source code 

*/

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

    for(int i=0; i<numNodes; i++) // Now this loop takes care of disconnected components. And also it might happen that there is no utgoing node from the current node 
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
