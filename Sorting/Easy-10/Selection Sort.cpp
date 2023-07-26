/*  Selection Sort */
/*  This algorithm will work for O(n^2) each time */
/*  Internally this algorithm maintains two subarrays - one of which is sorted and the other one is unsorted */
/*  This algorithm never makes more than O(n) swaps and is useful when memory writes can be an expensive operation. It is also a stable algorithm */
/*  Here too, the smallest element is placed at the first array index in the first outer iteration */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    int minIndex=0;
    
    for(int i=0; i<n; i++)
    {   
        for(int j=i+1; j<n; j++)
        {
            if(v[minIndex] > v[j])
                minIndex=j;
        }
        swap(v[i], v[minIndex]);
    }
    
    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    
    cout << endl;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  