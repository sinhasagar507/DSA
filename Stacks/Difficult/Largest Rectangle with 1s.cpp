/* 
	Largest-Rectangle-All 1s
*/

#include<bits/stdc++.h>
using namespace std;

// Time Complexity: Theta(n^2) 
// Calculate contiguous 1s in each row
// Finally use the approach to calculating largest area in a histogram *


int main()
{
	int n, m;
	cin >> n >> m;
	
	// Initializing a pre-defined 2-D vector
	vector<vector<int>> v(n, vector<int> (m)); 


	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cin >> v[i][j];
	}
	
	// Count Consecutive 1s in each array and store those counts for each row
	vector<int> cntMax(n, 0);
	
	
	for(int i=0; i<n; i++)
	{	
		int cnt=0;
		for(int j=0; j<m; j++)
		{
			if(v[i][j]==0)
				cnt=0;
				
			else
			{
				cnt++;
				cntMax[i] = max(cntMax[i], cnt);
			}
		}
	}
	
	
// Create two temporary arrays to store the indices of the previous and next smallest elements
// Create two stacks and push the requisite indexes as per the largest-histogram based algorithm 
	vector<int> psi(n), nsi(n);
	stack<int> s, s1;
	psi[0]=-1;
	nsi[n-1] = n;
	s.push(0);
	s1.push(n-1);

	for(int i=0; i<n; i++)
	{
		while(!s.empty() and cntMax[s.top()]>=cntMax[i])
			s.pop();
			
		psi[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}
	
	
	for(int i=n-1; i>=0; i--)
	{
		while(!s1.empty() and cntMax[s1.top()] >= cntMax[i])
			s1.pop();
			
		nsi[i] = s1.empty() ? n : s1.top();
		s1.push(i);
	}
	
	int res = 0;

	for(int i=0; i<n; i++)
	{
		int curr = cntMax[i];
		curr += (i-psi[i]-1) * cntMax[i];
		curr += (nsi[i]-i-1) * cntMax[i];
		res = max(res, curr);
	}		
	
	cout << res << endl;
	
	return 0;
}
	
