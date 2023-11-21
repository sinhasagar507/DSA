/*
Problem Statement: Leftmost Non-Repeating Character in a String 

Advantages: 
1. Works well for an incoming stream of characters 
 
 
Use Cases 
1. ...

*/

#include <bits/stdc++.h> 
using namespace std; 

const int CHAR=256;

int nonRep(string &str) // Time Complexity: theta(n+CHAR), Space Complexity: theta(char)
{
    // Initialize an array to keep track of the first occurrence index of each character
    int fI[CHAR];

    // Initialize all elements of the array to -1, indicating no occurrence yet
    fill(fI, fI + CHAR, -1);

    // Iterate through the characters in the input string
    for (int i = 0; i < str.length(); i++) {
        // Check if the character at str[i] has been seen before
        if (fI[str[i]] == -1) {
            // If it's the first occurrence, store the current index in the array
            fI[str[i]] = i;
        } else {
            // If the character has been seen before, mark it as a repeated character by setting the index to -2
            fI[str[i]] = -2;
        }
    }

    // Initialize a result variable to the maximum possible integer value
    int res = INT_MAX;

    // Iterate through the array to find the minimum index of the first non-repeating character
    for (int i = 0; i < CHAR; i++) {
        if (fI[i] >= 0) {
            // If the character has a non-negative index, it means it's non-repeating
            // Update the result if this character's index is smaller than the current result
            res = min(res, fI[i]);
        }
    }

    // If res is still equal to INT_MAX, no non-repeating character was found in the string, so return -1
    // Otherwise, return the index of the first non-repeating character
    return (res == INT_MAX) ? -1 : res;
}

int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<nonRep(str)<<endl;  
    
    return 0; 
} 