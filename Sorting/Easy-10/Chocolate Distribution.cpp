/* Chocolate Distribution problem */
/* Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets atleast one packet.
The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum. */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++)
        cin >> v[i];
      
    if(m > n)
    	cout<<"Sorry, the number of boys is greater than the number of chocolates"<<endl;
      
    else
    {
    	sort(v.begin(), v.end());
    	int mini = v[m-1]-v[0];
    	
    	for(int i=1; (i+m-1) < n; i++) 
    	{
    		mini = min(mini, v[i+m-1]-v[i]);
    	}  
    	
    	cout<<mini<<endl;  	
    }

	return 0;
}
