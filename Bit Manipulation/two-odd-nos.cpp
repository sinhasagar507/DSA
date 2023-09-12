/*
Refer the follwing video(s) for further revision: https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-BitMagic/video/MTQ5MDU%3D

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
#define INF INT_MAX 

void twoOdd(vector<int> &v, int n) // Time Complexity is O(n)...Auxiliary Space Complexity is O(1)
{	 
	int res = v[0], x1 = 0, x2 = 0; 
	
	for(int i = 1; i < n; i++)
		res = res^v[i]; 
		
	int k = res & (~(res - 1)); // This operation isolates the rightmost set bit of "x" and clears all other bits. It is mainly used to find the rightmost set bit in an integer 
	
	for(int j = 0; j < n; j++)
	{
		if(v[j] & k)
			x1 = x1 ^ v[j]; 
		else 
			x2 = x2 ^ v[j]; 
	}
	
	cout << x1 << " " << x2 << endl;  
}

// Maximum Time Complexity for the Spanning Tree will be O(V*(log E + log E))
int main()
{
    int n; 
    cin >> n; 
    vector<int> v(n); 
    
    for(int i = 0; i < n; i++)
    	cin >> v[i]; 
    	
    twoOdd(v, n); 
    return 0;
}