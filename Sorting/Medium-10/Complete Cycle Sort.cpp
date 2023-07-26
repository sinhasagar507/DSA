/* Cycle Sort - Complete */
// Inplace and unstable sorting algorithm 
// An algorithm that performs optimal number of writes to the original array. Each element is written in the minimum no. of times to its correct position 

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    	cin >> v[i];
    	
   
   for(int i = 0; i < n-1; i++)
   {
   		int pos = i;
   		int element = v[i];
   		
   		// We always check the upcoming elements only 
   		for(int j = i+1; j < n; j++)
   		{
   			if(v[j] < element)
   				pos++;
   		}
   		
   		// If position is the same as index, continue
   		if(pos == i)
   			continue;
   		
   		// This takes care of elements that aren't together. For example, {10, 30, 40}{20, 40, 20, 10, 10}
   	   	while(element == v[pos])
   			pos++;

   		
   		if(pos != i)
   		{
   			swap(element, v[pos]);
   			writes++;
   		}
   		
   		// Iterate till I get the desired element at the desired index
   		while(pos != i)
   		{
   			pos = i;
   			for(int j = i+1; j < n; j++)
   			{
   				if(v[j] < element)
   					pos++;
   			}
   			
   			
   			// This takes cares of repeated elements that aren't together
   			while(element == v[pos])
   				pos++;
   			
   			
   			
   			// Swap element the one at 'pos' index
   			if(element != v[pos])
   			{
   				swap(element, v[pos]);
   				writes++;
   			}   		
   		}		
   }
   
   for(int i = 0; i < n; i++)
   		cout << v[i] << " ";
   		
   cout << endl;
   return 0;
}
