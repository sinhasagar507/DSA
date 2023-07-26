/* Sieve of Erasthothenes. Printing all prime numbers less than a given number */
#include<bits/stdc++.h>
using namespace std;

/* 
int main()
{
	int n;
	cin >> n;
	
	vector<bool> isPrime(n+1, true);
	
	for(int i=2; i*i<=n; i++)
	{
		if(isPrime[i])
		{
			for(int j=2*i; j<=n; j+=i)
				isPrime[j] = false;
		}
	}
	
	for(int i=2; i<=n; i++)
	{
		if(isPrime[i])
			cout << i << " ";
	}
	
	cout << endl;
}

*/

/* Time Complexity of this algorithm is O(n loglogn) */
int main()
{
	int n;
	cin >> n;
	
	vector<bool> isPrime(n+1, true);
	
	for(int i=2; i<=n; i++)
	{
		if(isPrime[i])
		{	
			cout << i << " ";
			for(int j=i*i; j<=n; j+=i)
				isPrime[j]=false;
		}
	}
	
	cout << endl;
}