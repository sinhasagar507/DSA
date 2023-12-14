/*
Problem Statement: Distance of nearest cell having 1 
Problem Link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1

*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    // Overall TC: O(n*m). Space Complexity: O(n*m)
    vector<vector<int>> nearest(vector<vector<int>> grid) {
    // Declare variables for the grid size
    int n = grid.size();  // Number of rows in the grid
    int m = grid[0].size();  // Number of columns in the grid
    
    // Create two 2D vectors to track visited cells and distances
    vector<vector<int>> vis(n, vector<int>(m, 0));  // Tracks visited cells
    vector<vector<int>> dist(n, vector<int>(m, 0)); // Stores distances
    
    // Initialize a queue to perform BFS
    queue<pair<pair<int, int>, int>> q;  // Queue to perform BFS
    
    // Iterate through the grid to find cells containing ones. Runs in O(n*m)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                // For each cell containing 1, push its coordinates and distance 0 into the queue
                q.push({{i, j}, 0});
                // Mark the cell as visited
                vis[i][j] = 1;
            }
        }
    }
    
    // Define directions to explore adjacent cells: up, right, down, left (clockwise direction)
    int delrow[] = {-1, 0, +1, 0};  // Changes in row direction
    int delcol[] = {0, +1, 0, -1};  // Changes in column direction
    
    // Perform BFS. Here the TC is O(n*m*4). Study the queue 
    while (!q.empty()) {
        // Get the current cell's coordinates and distance from the queue
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        
        q.pop(); // Remove the current cell from the queue
        
        dist[row][col] = steps; // Store the distance for the current cell
        
        // Explore the four possible directions from the current cell
        for (int i = 0; i < 4; i++) {
            // Calculate new coordinates and distance for the adjacent cell
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            int nsteps = steps + 1;
            
            // Check if the adjacent cell is within the grid boundaries and not visited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                // Mark the adjacent cell as visited
                vis[nrow][ncol] = 1;
                // Push the adjacent cell's coordinates and distance into the queue
                q.push({{nrow, ncol}, nsteps});
            }
        }
    }
    // Return the 2D vector containing distances from ones to nearest zeroes
    return dist;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends