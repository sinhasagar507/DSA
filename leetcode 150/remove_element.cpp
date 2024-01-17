/* 
Refer this link for further notes: https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
*/ 

#include<bits/stdc++.h> 
using namespace std; 

void solve()
{
	int n, k; 
	cin >> n >> k; 
	
	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 
		
	int cntr = 0; 
	
	for(int i = 0; i < n; i++)
	{
		if(v[i] != k)
		{
			swap(v[i], v[cntr]); 
			cntr++; 
		}
		
	}
	
	for(int i = 0; i < n; i++)
		cout << v[i] << " "; 
		
	cout << "\n"; 
	cout << cntr << endl; 
	cout << "\n";
}

int main() 
{ 
	int t; 
	cin >> t; 
	
	while(t--)
	{
		solve(); 
	} 
}  