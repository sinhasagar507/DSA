/* Cycle Sort 
Refer this link: https://www.youtube.com/watch?v=JfinxytTYFQ
Whenever numbers given from 1 to N, use Cyclic Sort 
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n-1; i++)
    	cin >> v[i];
    	
   for(int i = 0; i < n; i++)
   {
   		int correct = i+1;
   		if(v[i] != correct)
   			swap(v[i], correct);
   		
   }
   
   for(int i = 0; i < n; i++)
    	cout << v[i] << " ";
   
	
   cout<<endl;
	
   return 0;
}
