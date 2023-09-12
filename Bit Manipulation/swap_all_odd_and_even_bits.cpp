#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
#define INF INT_MAX 


// Function to swap odd and even bits 
unsigned int swapBits(unsigned int n)
{
	// Get all even bits of x 
	unsigned int even_bits = n & 0xAAAAAAAA; 
	
	// Get all odd bits of x 
	unsigned int odd_bits = n & 0x55555555; 
	
	even_bits >>= 1; // Right shift even bits 
	odd_bits <<= 1; // Left shift odd bits 
	
	return (even_bits | odd_bits); // Combine even and odd bits 
}

int main()
{
	unsigned int n; 
	cin >> n; 
	
	cout << swapBits(n) << endl; 
	return 0; 
}