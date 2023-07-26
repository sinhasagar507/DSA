/* 
	Largest-Histogram-Area-Efficient-Solution 
*/

#include<bits/stdc++.h>
using namespace std;

/* Time Complexity: O(n) */

// For each bar, we have calculated the total area that can be comprised WRT that bar, across all bars. And then the maximum area is calculated out of all of them.
// We have used two stacks, AND employed two arrays for this purpose 

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n), psi(n), nsi(n);
	psi[0] = -1;
	nsi[n-1] = n;
	
	stack<int> s, s1;
	s.push(0);
	s1.push(n-1);
	
	for(int i=0; i<n; i++)
		cin >> v[i];
		
		
	for(int i=0; i<n; i++)
	{
		while(!s.empty() and v[s.top()]>=v[i])
			s.pop();
			
		psi[i] = s.empty() ? -1 : s.top();
		s.push(i);
	}
	
	
	for(int i=n-1; i>=0; i--)
	{
		while(!s1.empty() and v[s1.top()] >= v[i])
			s1.pop();
			
		nsi[i] = s1.empty() ? n : s1.top();
		s1.push(i);
	}
	
		
	int res = 0;
	
	for(int i=0; i<n; i++)
	{
		int curr = v[i];
		curr += (i-psi[i]-1) * v[i];
	    	curr += (nsi[i]-i-1) * v[i];
		
		res = max(res, curr);
	}
		
	cout << res << endl;
}
	
