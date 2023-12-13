#include <iostream>
#include <cmath>
using namespace std;


void printGroups(int arr[], int n)
{
        for (int i=1; i<n; i++)
        {
                // If current element is not the same as previous 
                if (arr[i] != arr[i-1])
                { 
                        // If it is same as first element 
                        // then it is starting of the interval to be flipped 

                        if (arr[i] != arr[0])
                                cout << "From " << i << "to "; 


                        // If it is not the same as previous 
                        // and same as first element, then previous element 
                        // is end of interval 

                        else 
                                cout << (i-1) << endl; 

                }
        }
        // Traverse through all array elements starting from the second element 
     

	if(arr[n - 1] != arr[0])
        cout << n - 1 << endl;
}



int main() {
	
     int arr[] = {0, 0, 1, 1, 0, 0, 0, 0, 1}, n = 9;

     printGroups(arr, n);
    
}