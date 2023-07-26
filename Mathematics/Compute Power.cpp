/* Compute Power. Efficient Solution */
#include<bits/stdc++.h>
using namespace std;

/* Time Complexity of this algorithm is O(logn) */

int power(int n, int p)
{	
	if(p==0)
		return 1;
		
	int temp = power(n, p/2);
	temp *= temp;
		
	if(p%2 == 0)
		return temp;
		
	else
		return temp*n;
}

int main()
{
	int n, p;
	cin >> n >> p;
	
	int ans = power(n, p);
	
	cout << ans << endl;
}


