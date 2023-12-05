// The following code is referred from the source: https://www.geeksforgeeks.org/stringstream-c-applications/
#include<bits/stdc++.h> 
using namespace std; 

int countWords(string str)
{
	// Breaking input into word 
	// using stringstream 
	
	/*
	Used for breaking words. breaks the incoming stream 
	by the specified delimiter(space by default) and processes 
	each word at a time
	*/
	stringstream s(str); 
	
	// To store individual words 
	string word; 
	
	int count = 0; 
	while (s >> word) // Read a word from the stringstream object s
		count++; 
		 
	string token; 
	while(getline(s, token, ' ')) // data types in order: getline(stringstream s, string str, char delim)
		cout << token << " "; 
		
	/*
	Some other methods on this object include: 
	1. clear() - to clear the stream
	2. str() - to get and set string object from the original stringstream object 
	3. operator << - add something to the stringstream object 
	4. operator >> - read something from the stringstream object 
	*/
		
	return count; 
}

// Driver Code 
int main()
{
	string s = "geeks for geeks geeks " "contribution placements"; // Strings can be easily concatenated together unlike in Python with/without using the "+" operator
	string s1 = "5,3,6,2,4,NULL, 7"; 
	cout << s << "\n"; 
	cout << "Number of words are: " << countWords(s); 
}