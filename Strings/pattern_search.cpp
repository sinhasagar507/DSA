/*
Pattern Search: Given a text txt[0..n-1] and a pattern pat[0..m-1], 
write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

			 
*/

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

void solve()
{
	// Do Something
	char txt[] = "ABCABCDABCD"; // A character array 
	char pat[] = "ABCD";
	
	int len1 = strlen(txt); // Returns the length of C string  
	int len2 = strlen(pat); 
	
	/* A loop to slide pattern[] one by one */
	// The following loop will run in both cases, whether characters in the pattern are distinct or repeated
	for(int i = 0; i < len1; i++)
	{
		int j; 
		for(j = 0; j < len2; j++)
		{
			if(txt[i+j] != pat[j])
				break; 
		}
		
		if(j == len2) 
			cout << "Pattern is found at index " << i << endl; 

	}
	
	/*
	for(int i = 0; i <= len1-len2; )
	{
		int j; 
		for(j = 0; j < len2; j++)
		{
			if(txt[i+j] != pat[j])
				break; 
		}
		
		if(j == len2) 
			cout << "Pattern is found at index " << i << endl; 
			
		else if (j == 0)
			i++; 
			
		else i += j; 
	}
	*/
	
	// To make sure that the loop runs only once when all characters are distinct
	
	/* Rabin Karp Algorithm: The time complexity of this algorithm here is: O((N-M+1)*M). It is used practically when then are multiple patterns to be searched in a text
	void RBSearch(pat, text, M, N) // Time Complexity: O(N - M + 1)
	{
		// M is the length of pattern 
		// N is the length of original string 
		int h = 1; 
		for(int i = 1; i <= M-1; i++)
			h = (h*d)%q; // Here I am computing (d^m-1)%q
			
		int p = 0; // Initializing hash function for the pattern 
		int h = 0; // Initializing hash function for the text 
		
		for(int i = 0; i < M; i++)
		{
			p = (p * d + pat[i])%q; 
			t = (t * d + txt[i])%q; 
		}
		
		for(int i = 0; i <= N-M; i++)
		{
			if(p == t)
			{
				bool flg = true; 
				for(int j = 0; j < M; j++){
					if(txt[i+j] != pat[j]){
						flag = false; 
						break; 
					}
					
				if(flag == true)
					print(i); 
				}
			}

			if(i < N-M){ // I need to stop this computation at last window 
				t = (d * (t - txt[i] * h) + txt[i+m])%q; // This could turn out to be negative at some instant as we are performing subtraction 
				if(t < 0) t += q;  
			} 
	  }
	*/
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