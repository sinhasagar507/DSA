/* Separate elements of 2 types */
/* The question can be framed as : Given an array consisting of positive and negative integers, or even or odd type integers or a binary array, segregate them into 2 types */
/* Hoare's partition can also be used here. It is also not an inplace solution. */
/* Does an inplace solution exist to the problem? */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin >> v[i];
      
	int inv=0;
	
	for(int i=0; i<n; i++)
	{
		if((v[i]%2==0) and inv<n)
		{
			swap(v[i], v[inv]);
			inv++;
		}
		
		else
			continue;
	}
	
	for(int i=0; i<n; i++)
		cout<<v[i]<<" ";
	
	cout<<endl;
	
	return 0;
}
