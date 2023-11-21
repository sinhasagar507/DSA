/* Sort an array of 3 types */

/* Its variations include
1. Soritng an array of 0s, 1s and 2s. 
2. Three way partitioning around a given pivot 
3. Partition around a range
*/	

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int m, n;
    cin >> m >> n;;
    
    vector<vector<int>> v(m, vector<int>(n));
    
    for(int i = 0; i < m; i++)
    {
    	for(int j = 0; j < n; j++)
    	{
    		cin >> v[i][j];
    	}
    }
    
    int index = v[0][0];
    int key = v[0][1];
    
    sort(v.begin(), v.end());
    
    vector<vector<int>> v1;
    vector<int> aux;

    for(int i = 1; i < m; i++)
    {
		if(key >= v[i][0] and key <= v[i][1])
			key = v[i][1];
		
		else if(key >= v[i][0] and key >= v[i][1])
			continue;
			
		else
		{
			aux.push_back(index);
			aux.push_back(key);
			v1.push_back(aux);
			index = v[i][0];
			key = v[i][1];
			aux.clear();
		}
    }
    
    aux.push_back(index);
    aux.push_back(key);
    v1.push_back(aux);
    
    for(int i = 0; i < v1.size(); i++)
    {
    	for(int j = 0; j < v1[i].size(); j++)
    	{
    		cout << v1[i][j] << " ";
    	}
    	
    	cout << endl;
    }
    

	return 0;
}
