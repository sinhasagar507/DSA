#include <bits/stdc++.h>
using namespace std;

// Helper function to find the minimum sum path from (i, j) to (0, 0) in the matrix
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
    if (i < 0 || j < 0)
        return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

// Main function to find the minimum sum path in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}

/*
// Tabulation Code 
// Function to calculate the minimum sum path in a 2D grid
int minSumPath(int m, int n, vector<vector<int>> &matrix)
{
    // Initialize a DP table with size m*n to store minimum path sums 
    vector<vector<int>> dp(m, vector<int>(n, 0)); 

    // Iterate over the grid
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            if(i == 0 and j == 0)
                dp[i][j] = matrix[i][j]; 
            else
            {
                // If we are not on the first row or first column
                if(i > 0 and j > 0)
                    // Store the minimum path sum in dp[i][j] by adding the current cell value to the minimum of the top and left cell values
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i][j-1]); 
                    
                // If we are on the first row and not on the first column
                else if (i == 0 and j > 0)
                    // Store the minimum path sum in dp[i][j] by adding the current cell value to the left cell value
                    dp[i][j] = matrix[i][j] + dp[i][j-1]; 
                    
                // If we are on the first column and not on the first row
                else 
                    // Store the minimum path sum in dp[i][j] by adding the current cell value to the top cell value
                    dp[i][j] = matrix[i][j] + dp[i-1][j];
            }
        }
    }

    // Return the minimum path sum which is stored in the bottom-right cell of the DP table
    return dp[m-1][n-1]; 
}
*/ 

int minSumPath(int m, int n, vector<vector<int>> &matrix)
{
    // Initialize a DP table with size m*n to store minimum path sums 
    vector<vector<int>> dp(m, vector<int>(n, 0)); // Is 

	// Create a 1D row vector which takes care of the row value bove the particular cell (past state)
	vector<int> prev(n, 0); 
	
    // Iterate over the grid
    for(int i = 0; i < m; i++)
    {
    	// Create a 1D current row vector which takes care of the column value to the left of a particular cell (current state)
        vector<int> temp(n, 0); 
        for(int j = 0; j < n; j++)
        {
       
            // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            if(i == 0 and j == 0)
                temp[j] = matrix[i][j]; 
            else
            {
                // If we are not on the first row or first column
                if(i > 0 and j > 0)
                    // Store the minimum path sum in temp[j] by adding the current cell value to the minimum of the top and left cell values
                    temp[j] = matrix[i][j] + min(prev[j], temp[j-1]); 
                // If we are on the first row and not on the first column
                else if (i == 0 and j > 0)
                    // Store the minimum path sum in dp[i][j] by adding the current cell value to the left cell value
                    temp[j] = matrix[i][j] + temp[j-1]; 
                // If we are on the first column and not on the first row
                else 
                    // Store the minimum path sum in dp[i][j] by adding the current cell value to the top cell value
                    temp[j] = matrix[i][j] + prev[j];
            }
        }
        prev = temp; // Update the previous row with the current row 
    }

    // The final result is stored in prev[m-1], which represents the destination in the last column
    return prev[n-1]; 
}

// Function to find the minimum sum path from (0, 0) to (m-1, n-1) respectively 
int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}