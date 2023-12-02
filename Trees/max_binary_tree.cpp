/*
Problem Statement: Convert a binary tree to doubly linked list 
Specific Applications: None 
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

struct TreeNode { 
	int data; 
	TreeNode *left, *right; 
	TreeNode(int x) 
	{ 
		data = x; 
		left = right = nullptr;
	} 
};


TreeNode* prevNode = nullptr; 
TreeNode* head = nullptr; 

// Returns maximum value in a given 
// binary tree 
// Time Complexity: O(n)
// Aux Space Complexity: O(n) (Due to the recursion tree stack)
int findMaxElement(TreeNode* root)
{
	// Base Case 
	if(root == nullptr)
		return INT_MIN; 
		
	// Return max of 3 values 
	// 1) Root's data 2) Max in left subtree 
	// 3) Max in right subtree 
	
	int res = root->data; 
	int lres = findMax(root->left); 
	int rres = findMax(root->right); 
	
	res = max(res, max(lres, rres)); 
	return res; 
}

void solve()
{   
	// Do Something 
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(12);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(30);
	root->right->left = new TreeNode(36);
	
	// Original tree preorder traversal 
	int maxElement = findMaxElement(root); 
	cout << maxElement << "\n"; 
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