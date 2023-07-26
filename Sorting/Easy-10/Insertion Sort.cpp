/* Insertion Sort */
/* Insertion sort is efficient when the number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in the complete big array. */
/* It is a stable and in-place sorting algorithm. Since it processes inputs in a serial fashion, it is an online algorithm. */
/* Insertion sort takes a maximum of O(n) time if the input is already sorted and takes O(n^2) time on average. */

#include<bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    for(int i = 1; i < n; i++)
    {   
        int j = i - 1;
        int key = v[i];
        while(j >= 0 and v[j] > key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}
