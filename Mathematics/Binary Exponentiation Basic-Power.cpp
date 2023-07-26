/* Compute Power. Efficient Solution. Binary Exponentiation */
#include<bits/stdc++.h>
using namespace std;

/* Time Complexity of this algorithm is O(logn) */

int power(int n, int p)
{	
	int res = 1;
	while(p>0)
	{
		if(p%2 != 0)
			res *= n;
		
		
		n *= n;
		
		p /= 2;	
	}
	
	return res;
}

int main()
{
	int n, p;
	cin >> n >> p;
	
	int ans = power(n, p);
	
	cout << ans << endl;
}


