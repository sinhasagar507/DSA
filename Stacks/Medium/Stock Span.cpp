/* Given a list of prices of a stock for N days. The task is to find the stack span for each day.
Stock span can be defined as the number of consecutive days before the current day where the price of the stack was equal to or less than the current price. 
*/

#include<bits/stdc++.h>
using namespace std;

/* Time Complexity : Amortized Time Complexity = O(n) */

void printSpan(vector<int> &v, int n, stack<int> &s)
{
	for(int i=1; i<n; i++)
	{
		while(!s.empty() and v[s.top()]<=v[i])
			s.pop();
			
		int span = s.empty() ? i+1 : i-s.top();
		cout << span << " ";
		s.push(i);
	}
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	stack<int> s;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
		
	s.push(0);
	cout << 1 << " ";
	
	printSpan(v, n, s);
	
}


