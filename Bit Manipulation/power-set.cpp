/*
Problem Statement: Power Set - Power set P(S) of a set S is the set of all subsets of S.  
				   For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
                   If S has n elements in it then P(s) will have 2n elements. 
Refer the follwing video(s) for further revision: https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-BitMagic/video/Nzc0OA%3D%3D
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
#define INF INT_MAX 

void powerSet(string s) // Time Complexity is O(n*2^n)...Auxiliary Space Complexity is O(1)
{	 
	int n = s.length(); 
	int pow = 1 << n; 
	
	for(int i = 0; i < pow; i++) // 2^n
	{ 
		for(int j = 0; j < n; j++) // n
		{
			if(i & (1 << j)) // Condition to check for Power Set 
				cout << s[j]; 
		}
			
		cout << endl; 
	}
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))
int main()
{
	string s; 
	cin >> s; 
    	
    powerSet(s); 
    return 0;
}