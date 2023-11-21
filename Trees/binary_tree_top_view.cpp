/*
Problem Statement: Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
				   Given a binary tree, print the top view of it. The output nodes can be printed in any order. Expected time complexity is O(n)

Applications of printing top view of binary tree 
- Visual Representation: For visualizing and understanding the structure of a binary tree. Displaying the top view can help in comprehending the overall shape and distribution of nodes 
- Optimizing Navigation Systems: In hierarchical systems like file directories or organizational structures, displaying the top view helps in providing a quick overview of the main branches or categories.
- Network Routing: In network routing algorithms or distributed systems, understanding the topological structure of the network or the hierarchy of nodes is crucial. The top view might provide insights into the main nodes or hubs.
- Tree Visualization in Data Structures: For educational or debugging purposes when teaching or understanding tree-related data structures, showing the top view helps in illustrating how nodes are arranged and connected.
- Pathfinding Algorithms: In algorithms that require traversing or searching through a tree-like structure, such as graph algorithms or certain AI search algorithms, knowing the top view might aid in optimizing the pathfinding process.
- User Interface Design: When designing user interfaces or navigation menus with dropdowns or hierarchies, understanding the top-level nodes or categories helps in structuring the interface effectively.
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
	TreeNode *lchild, *rchild; 
	TreeNode(int x) 
	{ 
		data = x; 
		lchild = rchild = NULL;
	} 
};

// Binary Tree Top View
vector<int> topView(TreeNode* root)
{
	vector<int> ans; 
	if(root == NULL)
		return ans; 
		
	map<int, int> mpp; 
	queue<pair<TreeNode*, int>> q; 
	q.push({root, 0});
	
	while(!q.empty())
	{
		auto it = q.front(); 
		q.pop(); 
		TreeNode* node = it.first; 
		int line = it.second; 
		if(mpp.find(line) == mpp.end())
			mpp[line] = node->data; 
			
		if(node->left != NULL)
			q.push({node->left, line-1}); 
			
		if(node->right != NULL)
			q.push({node->right, line+1}); 	
	}
	
	for(auto it: mpp)
		ans.push_back(it.second); 
		
	return ans; 
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
	
	vector<int> res = topView(root); 
	
	for(auto it: res)
		cout << it << " "; 
		
	cout << "\n"; 
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