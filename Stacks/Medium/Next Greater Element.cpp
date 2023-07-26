/* 
Next Greater Element
*/

#include<bits/stdc++.h>
using namespace std;

/* Time Complexity : Amortized Time Complexity = O(n) */
/* Space Complexity : Amortized Space Complexity = O(n) */

void printNextGreater(vector<int> &v, int n, stack<int> &s, stack<int> &s1)
{	
	for(int i=n-2; i>=0; i--)
	{
		while(!s.empty() and s.top()<v[i])
			s.pop();
			
		int greaterElement = s.empty() ? -1 : s.top();
		s1.push(greaterElement);
		s.push(v[i]);
	}
	
	while(!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	stack<int> s, s1;
	
	for(int i=0; i<n; i++)
		cin >> v[i];
		
	s.push(v[n-1]);
	s1.push(-1);
	
	printNextGreater(v, n, s, s1);
	
}

