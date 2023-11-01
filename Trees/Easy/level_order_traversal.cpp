/*
Problem Statement: Level Order traversal of a tree is breadth first traversal of a tree. 
				   Perform the same. 
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

struct Node
{
	int key; 
	struct Node *left, *right; 
	Node(int k)
	{
		key = k; 
		left = right = NULL; 
	}
}; 

/*
Time Complexity of this traveral routine is theta(n). 
The auxiliary space is O(n) when the tree is a balanced one, IOR Theta(w) is the width of binary tree
When its one-sided, then the space complexity is theta(1). 
Ovrall time complexity of both algorithms is thetaa(n), where "n" is the total no. of nodes 
in a binary tree. 
*/

void printLevel(Node *root) 
{   
	// Do Something 
	if(root == NULL)
		return; 
		
	queue<Node *> q; 
	q.push(root); 
	
	while(!q.empty())
	{
		Node *curr = q.front(); 
		q.pop(); 
		cout << curr->key << " "; 
		
		if(curr->left != NULL)
			q.push(curr->left); 
			
		if(curr->right != NULL) 
			q.push(curr->right); 
	}
}

void solve()
{
	Node *root = new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);
	
	printLevel(root);
}
 
int main()
{
	solve(); 
	return 0; 
}