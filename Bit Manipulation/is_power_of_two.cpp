// C++ program of the above approach

#include <bits/stdc++.h>
using namespace std;

/* Function to check if x is power of 2*/
bool isPowerofTwo(long long n)
{
	return (n != 0) && ((n & (n - 1)) == 0);
}

// Driver code
int main()
{
	// Function call
	isPowerofTwo(30) ? cout << "Yes\n" : cout << "No\n";
	isPowerofTwo(128) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
