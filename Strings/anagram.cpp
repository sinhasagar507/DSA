/*
Anagram Check: 
	Check if 2 strings are anagrams 
	For 2 given strings, check if thery are just permutations of each other, i.e., the set of characters 
	in both the strings is the same 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
#define NO_OF_CHARS 256 
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

bool areAnagram(string str1, string str2)
{
	// Create 2 count arrays and initialize them to 0 
	int count1[NO_OF_CHARS] = {0};
	int count2[NO_OF_CHARS] = {0};
	
	// For each character in input strings, increment count 
	// in the corresponding count array 
	int i; 
	for(i = 0; str1[i] and str2[i]; i++) // The condition in the for loop specifies if there exists a character at the specified index position 
	{
		count1[str1[i]]++; 
		count2[str2[i]]++; 
	}
	
	// If both strings are of different lengths, removing 
	// this condition will make the program fail for strings 
	// like 'aaca' and 'aca'
	if(str1[i] and str2[i])
		return false; 
		
	// Compare count arrays 
	for(i = 0; i < NO_OF_CHARS; i++)
		if(count1[i] != count2[i])
			return false; 
			
	return true;	
}

void solve()
{
	// Do Something 
	string s, s1; 
	cin >> s >> s1; 
	
	// Function call 
	if(areAnagram(s, s1))
		cout << "The two strings are anagram of each other"; 
	else 
		cout << "The two strings are not anagrams of each other"; 	
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