/*
Problem Statement:	The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes

Applications of getting diameter of binary tree
- Network Routing Optimization: Helps optimize routing algorithms in computer networks.
- Performance Analysis: Assists in analyzing the efficiency of binary tree-based data structures.
- Balancing Binary Trees: Used in balancing structures like AVL or Red-Black trees for optimal operations.
- Graph Algorithms: Provides insights for graph traversal algorithms and connected components.
- Algorithm Design: Crucial parameter in algorithms for tree-related problems and optimizations.
- Social Network Analysis: Measures maximum distance between individuals in social networks.
- Algorithmic Competitions: Critical metric or constraint in tree-related algorithmic challenges.
- Parallel Computing: Assists in designing efficient communication protocols and algorithms.
- Robotics and Sensor Networks: Aids in movement strategies for robots or sensor nodes.
- Tree Visualization: Contributes to understanding the overall structure of trees in visualizations.
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
		left = right = NULL;
	} 
};

//  Diameter of a binary tree 
/// A naive solution would be to find lheight and rheight and just add 1. As presented here...
//  Time Complexity of this algorithm: O(n)
//  Space Complexity: O(h). However, if the tree is skewed, then the SC is O(n)
int height(TreeNode* node, int &diameter)
{
	if(node == NULL)
		return 0; 
		
	int lh = height(node->left, diameter); 
	int rh = height(node->right, diameter); 
	diameter = max(diameter, lh+rh); 
	return 1 + max(lh, rh); 
}

// Function to insert a new node in Binary Tree 
void solve()
{   
	// Do Something
	// Construct the tree 
	TreeNode* root = new TreeNode(1); 
	root->left = new TreeNode(2); 
	root->left->left = new TreeNode(4); 
	root->left->right = new TreeNode(5); 
	root->left->right->left = new TreeNode(6); 
	root->right = new TreeNode(3); 
	root->right->right = new TreeNode(7); 
	int diameter = 0; 
	int h = height(root, diameter); 
	cout << h << " " << diameter << "\n"; 
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