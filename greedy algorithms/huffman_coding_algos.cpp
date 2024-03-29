/*
Problem Statement: // Huffman Coding
1. It is a variable length lossless decompressing technique
2. It is a greedy algorithm. The most frequent algorithm is going to have the smallest code and vice versa. 
3. No code should be a prefix of another code. Can't decode in such a scenario. 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
const int CHAR = 256; 
 
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


/*
Steps involved in Huffman Encoding-Decoding
1. Create a frequency array and store all the characters in a priority queue 
2. Till the priority queue ain't empty, keep inserting the characters with minimal frequency so they are assigned normal codes 

*/

struct Node
{
	char data; // The character stored at each node 
	unsigned freq; 
	Node* left; 
	Node* right; 
	
	Node(char data, unsigned freq): data(data), freq(freq), left(nullptr), right(nullptr) {}
	
	~Node()
	{
		delete left; 
		delete right; 
	}
}; 

bool comparator(Node* left, Node* right)
{
	return left->freq > right->freq; 
}

// Till now mujhe ye lgg rha hai ki ki main bottom up se kaise tree bnaun...Kehne ko toh abhi bhi hai hi vo baat 

void encode(Node* root, string str)
{
	if(root == nullptr)
		return; 
		
	if(!root->left and !root->right)
		huffManCode[root->data] = str; 
		
	encode(root->left, str+"0"); 
	encode(root->right, str+"1"); 
}

void solve() 
{   
	// Do Something
	string text; 
	cin >> text; 
	
	int n = text.size(); 
	unordered_map<char, int> freq; 
	
	for(int i = 0; i < n; i++) 
		freq[text[i]]++; 
		
	// Declare a CUSTOM max-heap 
	priority_queue<Node*, vector<Node*>, comparator> pq; 
	for(auto pair: freq)
		pq.push(new Node(pair.first, pair.second)); 
		
	while(pq.size() != 1)
	{
		Node* left = pq.top(); 
		pq.pop(); 
		
		Node* right = pq.top(); 
		pq.pop(); 
		
		unsigned sumFreq = left->freq + right->freq; 
		pq.push(new Node("\0", sumFreq, left, right)); 
	}
	
	Node* root = pq.top(); 
	pq.pop(); 
	
	encode(root, ""); 
	delete root; 
	
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