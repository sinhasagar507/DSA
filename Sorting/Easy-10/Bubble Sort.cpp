/* Bubble Sort with Time Measurement */
/* The best-case time complexity of bubble sort is O(n). It occurs if the array is already sorted. */
/* Sorting occurs in-place */
/* It is a stable algorithm */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    auto start = chrono::high_resolution_clock::now();

    for(int i=0; i<n-1; i++)    // Total no. of passes 
    {   
        bool swapped = false;
        for(int j=0; j<n-i-1; j++)   // Total no. of swaps within the passes 
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        
        if(swapped == false)
                break;
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    double timeTaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    timeTaken *= 1e-9;

    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
        
    cout << endl;
    cout << timeTaken << setprecision(9) << "sec"<< endl;
}
