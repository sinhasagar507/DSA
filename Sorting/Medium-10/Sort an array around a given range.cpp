/* Sort an array of 3 types */

/* Its variations include
1. Sortng an array of 0s, 1s and 2s. 
2. Three way partitioning around a given pivot 
3. Partition around a range
*/	

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    	cin >> v[i];
    	
    int low = 0, mid = 0, high = n-1;
    
    while(mid <= high)
    {
    	if(v[mid] == 0 )
    		swap(v[low++], v[mid++]);
    		
    	else if(v[mid] == 1)
    		mid++;
    		
    	else
    		swap(v[mid], v[high--]);
	}
    
    for(int i = 0; i < n; i++)
    	cout << v[i] << " ";
	
	cout<<endl;
	
	return 0;
}
