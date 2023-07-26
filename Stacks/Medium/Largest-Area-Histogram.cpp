/* 
Largest Area in a histogram. Inefficient solution 
*/

#include<bits/stdc++.h>
using namespace std;

/* Time Complexity: O(n^2) */

int main()
{
	int n;
	cin >> n;
	
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
		cin >> v[i];
		
	int res = 0;
	
	for(int i=0; i<n; i++)
	{
		int curr = v[i];
		
		for(int j=i-1; j>=0; j--)
		{
			if(v[j]>=curr)
				curr += curr;
			else
				break;
		}
		
		
		for(int j=i+1; j<n; j++)
		{
			if(v[j]>=curr)
				curr+=curr;
			else
				break;
		}
		
		res = max(res, curr);
	}
	
	cout << res << endl;
}
	
/*
Efficient Solution Using Stacks 

*/
