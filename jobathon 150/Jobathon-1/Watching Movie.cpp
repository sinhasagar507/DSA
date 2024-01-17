#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int n, k;
	int cnt=1;
	cin >> n >> k;
	vector<int> v(n), ngi(n);
	
	for(int i=0; i<n; i++)
		cin>>v[i];
		
	// Stores the index of next greater or equal element 
	stack<int> s;
	
	s.push(n-1);
	ngi[n-1] = -1;
	
	for(int i=n-2; i>=0; i--)
	{
		while(!s.empty() and v[i]>v[s.top()])
			s.pop();
			
		ngi[i] = s.empty()?-1: s.top();
		s.push(i);
		
	}
	
	for(int i=0; i<n; i++)
		cout << ngi[i] << " ";
	cout << endl;
	
	for(int i=n-2; i>=0; i--)
	{
		if(ngi[i]==-1)
			cnt++;
			
		else if(n-(i+1) > k)
		{
			if((ngi[i]-i-1) > k)
				cnt++;
		}
	}
	
	cout << cnt << endl;

	return 0;

} 


