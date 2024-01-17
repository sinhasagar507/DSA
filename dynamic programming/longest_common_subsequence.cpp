/*
Problem Statement: Longest Common Subsequence (jo aa rha hai dimaag mein that's good...bss strings ki order maintain honi chahiye)
*/

#include<bits/stdc++.h> 
using namespace std; 

/*
What is the first thing which comes to mind??
- Generate all possible subsequences (using powerset OR recursion) for both arrays AND then compare on the go 
- Fir sbko hashset mein daalde AND dusre ke liye loop chlade...
- Compare AND done 
*/

/*
Recursive Approach 
- Express everything in terms of indices 
- Do stuff on that index 
- Count OR Max/Min 

int lcsLength(s1, s2, i1, i2)
{
	if(s1[i1] == s2[i2])
		return 1 + lcsLength(s1, s2, i1-1, i2-1); 
		
	return 0 + max(lcsLength(s1, s2, i1-1, i2), lcsLength(s1, s2, i1, i2-1)); 
}
*/

int main()
{
	return 0; 
}
