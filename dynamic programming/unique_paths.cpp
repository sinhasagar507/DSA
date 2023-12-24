/*
Problem Statement: You are present at point "A" which is the top-left of an M*N matrix, your destination is point "B", which is the bottom-right
				   cell 
Problem Statement Link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470?resumeRedirection=true&leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h> 
using namespace std;

int f(int i, int j, vector<vector<int>> &dp) 
{
  if (i == 0 or j == 0)
    return 1;

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = f(i - 1, j, dp);
  int left = f(i, j - 1, dp);

  return dp[i][j] = up + left;
}

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1)); 

	return f(m-1, n-1, dp); 
}