/*
Problem Statement: Given an array arr[] of size n, its prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i]
Time Complexity: If we can directly compute it at input time, then its theta(1). 
Space Complexity: theta(n)
*/

#include <iostream>
#include <cmath>
using namespace std;

int getSum(int ps[], int l, int r){
    if(l==0)
        return ps[r];
    return ps[r]-ps[l-1];
}

int main(){
    int arr[]={2, 8, 3, 9, 6, 5, 4};
    int n=7;
    int ps[n];
    ps[0] = arr[0];
    for(int i=1; i<n; i++)
        ps[i] = ps[i-1]+ arr[i];
        
   	cout<<getSum(ps,1,3); 
    return 0;
}