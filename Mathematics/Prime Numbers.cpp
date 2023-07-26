/* Printing prime factors of a number(With Repeated Factors) */

#include<bits/stdc++.h>
using namespace std;

/*
int main()
{	
	int n;
	cin >> n;
	
	if(n<=1)
		cout << "None" << endl;
		
	else
	{
			
		for(int i=2; i*i<=n; i++)
		{	
			while(n%i==0)
			{
				cout << i << " ";
				n = n/i;
			}
		}
		
		if(n>1)
			cout << n << endl;
	}

	return 0;
}
*/

/* Printing All Prime Factors(Prime Divisors) Efficient Solution - Fastest Solution. Takes 1/3rd of the time taken by previous algorithm */

int main()
{
	int n;
	cin >> n;
	

	if(n<=1)
		cout << "None" << endl;
			
	else
	{
		while(n%2==0)
		{
			cout << 2 << " ";
			n = n/2;
		}
			
		while(n%3==0)
		{
			cout << 3 << " ";
			n = n/3;
		}
			
		for(int i=5; i*i<=n; i+=6)
		{
			while(n%i==0)
			{
				cout << i << " ";
				n = n/i;
			}
				
			while(n%(i+2)==0)
			{
				cout << i+2 << " ";
				n = n/i;
			}
		}
			
		if(n>3)
			cout << n << " ";

	}
	
	cout << endl;
}
