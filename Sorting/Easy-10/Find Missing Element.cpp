/* 
Find the missing number 
*/


// Solution - 1

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n, count = 1, element;
    cin >> n;
    
    unordered_set<int> s;
    
    for(int i = 0; i < n; i++)
    {
    	int a;
    	cin >> a;
    	s.insert(a);
    }
    
    	
   for(auto it = s.begin(); it != s.end(); it++)
   {	
   		element = count;
   		if(s.find(element) == s.end())
   			break;
   			
   		count++;
   	}
   
	cout << element << endl;
   
   return 0;
}
*/

// Solution - 2

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n, count = 1, element;
    cin >> n;
    
    unordered_set <int> s;
    
    for(int i = 0; i < n; i++)
    {
    	int a;
    	cin >> a;
    	s.insert(a);
    }
    
    	
   for(auto it = s.begin(); it != s.end(); it++)
   {	
   		element = count;
   		if(s.find(element) == s.end())
   			break;
   			
   		count++;
   	}
   
	cout << element << endl;
   
   return 0;
}