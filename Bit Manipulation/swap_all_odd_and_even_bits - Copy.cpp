#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // Represents (node, weight) pair 
#define INF INT_MAX 


// Function to swap odd and even bits 
unsigned int swapBits(unsigned int n)
{
	// Get all even bits of x 
	unsigned int even_bits = n & 0xAAAAAAAA; // Represented in binary form as (10101010101010101010101010101010)
	
	// Get all odd bits of x 
	unsigned int odd_bits = n & 0x55555555; // Represented in binary form as (01010101010101010101010101010101)
	
	// We know that the presence of 1s help us detect nos at that position 
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