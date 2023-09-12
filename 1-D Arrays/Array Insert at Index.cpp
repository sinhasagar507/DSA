/*
Problem Statement: Insert element at given index 
Time Complexity: theta(1)
Space Complexity: theta(1)
*/

#include <stdio.h>
void insertAtEnd(int arr[],int sizeOfArray,int element)
{
    arr[sizeOfArray-1]=element;
}

int main() {
    int t;
    
    //taking testcases
    scanf("%d", &t);
    while(t--)
    {
        int sizeOfArray;
        
        //input size of Array
        scanf("%d", &sizeOfArray);
        
        int arr[sizeOfArray];
        
        //inserting elements in the array
        for(int i=0;i<sizeOfArray-1;i++)
            scanf("%d", &arr[i]);
        
        //input element to be inserted
        int element;
        scanf("%d", &element);
        
        //calling insertAtEnd() function
        insertAtEnd(arr,sizeOfArray,element);
        
        //printing the elements of the array
        for(int i=0;i<sizeOfArray;i++)
            printf("%d ", arr[i]);
        
        printf("\n");
        
    }
	return 0;
