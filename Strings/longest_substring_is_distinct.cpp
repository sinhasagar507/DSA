/*
Problem Statement: Given a string str, find the length of the longest substring 
				   without repeating characters 
				   
Example:

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
For “BBBB” the longest substring is “B”, with length 1.
For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7

Applications of the algorithm: 
1. Validating user input: For example, you could use substring check to ensure that a user enters a valid email address or phone number.
2. Formatting data: For example, you could use substring check to reformat a phone number to a standard format.
3. Extracting data from APIs: When interacting with APIs, responses often include unwanted information or excess data. Using substring check, you can extract only the required data.
4. Searching and filtering data: For example, you could use substring check to search for a specific term in a dataset or to filter a list of items based on a particular criteria.
5. Manipulating strings: For example, you could use substring check to change the format of a string, such as by converting all uppercase letters to lowercase.
*/

// Approach: Brute Force, Better, followed by most optimal approach 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
 
template <class T>
	ll giveNcR(ll n, ll r){ll p = 1, k = 1; if(n-r < r) r = n - r; if(r != 0){while(r) {p *=n; k *=r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; 
	return p;}
	
 
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
int no_of_digits(ll n){return 1 + floor(log10(n));}
 
vector<int> graph[N+1];
bool visited[N+1];
int dist[N+1];
int source[N+1];
queue<int> node_queue;


// Time Complexity: O(2n), Space Complexity: O(n)
/* Why the current time complexity is O(2n)? 
Ans. Because of the weird update rule encountered when there are multiple repeating characters. 
	 I update lptr only by 1 fpr each repeating character when in reality I could update it to lptr+1...
	 Study the example of the test case: abcaabcdba

void solve()
{   
	// Do Something
	string s;
	unordered_set<char> us; 
	 
	cin >> s;
	int n = s.length();
	
	if(n==0)
	{
		cout << "0\n"; 
		return;  
	}
		
	
	int lptr = 0, rptr = 0; 
	int res = 0; 
	while(lptr < n and rptr < n)
	{
		if(us.find(s[rptr]) == us.end())
		{
			us.insert(s[rptr]); 
			rptr++;
		}
		
		else
		{
			us.erase(s[lptr]); 
			lptr++;
			res = max(res, rptr - lptr + 1);
		}
	}
	
	cout << res << endl; 
}
*/ 

// The following updated algorithm solves the aforementioned issue and takes 
// exactly O(n) time and O(256) auxiliary space...which is infact O(1)
int solve()
{
    // Initialize variables
    string s;
    vector<int> mpp(256, -1); // Initialize an array to store the most recent index of each character
    
    cin >> s;
    int n = s.length();
    
    if (n == 0)
    {
        cout << "0\n"; // If the string is empty, the longest substring is of length 0
        return 0;
    }

    int left = 0; // Initialize the left pointer
    int right = 0; // Initialize the right pointer
    int len = 0; // Initialize the length of the longest substring
    
    while (right < n)
    {
        // If the character at 's[right]' has been seen before,
        if (mpp[s[right]] != -1)
        {
            // Update 'left' to be the maximum of the previous index of 's[right]' + 1 and the current 'left'
            left = max(mpp[s[right]] + 1, left);
        }
        
        // Update the most recent index of 's[right]' to 'right'
        mpp[s[right]] = right;
        
        // Update 'len' to be the maximum of the previous 'len' and the current substring length
        len = max(len, right - left + 1);
        
        right++; // Move the 'right' pointer to the right
    }
    
    return len; // Return the length of the longest substring with distinct characters
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin >> t;
 
	while(t--){
	solve(); 
	}
}