/* String Permutations */
#include <bits/stdc++.h> 
using namespace std; 

void permutation(string str, string perm)
{
    if (str.size()==0)
    {
        // Base Case 
        cout << perm << endl; 
        return; 
    }
    
    unordered_set<char> s; 
    for(int i=0; i<str.size(); i++)
    {
        char ch = str[i]; // current character 
        if (s.count(ch)==0)
        {
            string ros = str.substr(0, i) + str.substr(i+1); // rest of remaining string after leaving out ch
            s.insert(ch); // Handles permutation at each level 
            permutation(ros, perm+ch); 
        }
    }
}

int main()
{
    string s; 
    cin >> s; 
    permutation(s, ""); 
    return 0; 
}