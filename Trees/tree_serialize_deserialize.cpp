/*
Problem Statement: 
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

struct TreeNode { 
	int data; 
	TreeNode *left, *right; 
	TreeNode(int x) 
	{ 
		data = x; 
		left = right = nullptr;
	} 
};


// Function for performining serialization of binary tree 
/*
void serialize(TreeNode* node, vector<int> &serialized_res, unordered_map<TreeNode*, bool> &isLeafMap, queue<TreeNode*> &node_queue)
{
	if(node == nullptr)
	{
		serialized_res.push_back(-1); // Base case for null node
		return; 
	}

	else 
	{
		node_queue.push(node);
	
		while(!node_queue.empty()) 
		{
			TreeNode *top_node = node_queue.front();
			node_queue.pop(); 
			
			if(top_node != nullptr)
				serialized_res.push_back(top_node->data); 
				
			else 
				serialized_res.push_back(-1); 
				
			
			
			if(top_node->left != nullptr)
				node_queue.push(top_node->left); 
			
			else if((top_node->left == nullptr) and (isLeafMap[top_node] == false))
				node_queue.push(nullptr);
			
			
			if(top_node->right != nullptr)
				node_queue.push(top_node->right);
			
			else if((top_node->right == nullptr) and (isLeafMap[top_node] == false))
			    node_queue.push(nullptr);
			    
		}
	
	}
}
*/

void serialize(TreeNode* root, vector<int> &serialized_res, queue<TreeNode*> &node_queue)
{
	if(root == nullptr)
	{
		serialized_res.push_back(-1); 
		return; 
	}
		
	node_queue.push(root); 
	
	while(!node_queue.empty())
	{
		TreeNode *currNode = node_queue.front(); 
		node_queue.pop(); 
		
		if(currNode == NULL)
			serialized_res.push_back(-1); 
			
		else 
			serialized_res.push_back(currNode->data); 
			
		if(currNode != nullptr)
		{
			node_queue.push(currNode->left); 
			node_queue.push(currNode->right); 
		}
	}
	
	string s = "geeks for geeks geeks" "ontribution placements"; 
	cout << s << "\n"; 
}

// Word Counting 
while(s>>word)
{
#include <iostream>
#include <sstream>
#include <string>

int main() 
{
    // Create a stringstream containing comma-separated values
    std::string data = "10,20,#,30,#,#,40,#,#";

    // Create a stringstream object using the data string
    std::stringstream s(data);

    std::string str;
    while (getline(s, str, ',')) {
        // Output each extracted string separated by commas
        std::cout << str << " ";
    }

    return 0;
}
	
	
while(!q.empty())
// Decodes your data back to tree 
/* Do something 
void deserialize(vector<int> &serialized_res)
{
	if(serialized_res.size() == nullptr) 
	string s; 
	
	getline(s, str, ''); 
	TreeNode *root = new TreeNode(stoi(str)); 
	queue<TreeNode*> q; 
	q.push(root); 
	
	while(!q.empty())
	{
		TreeNode *node = q.front(); 
		q.pop(); 
		
		getline(s, str, ',');
		
		if(str=='#')
			node->left = null; 
			
		else 
		{
			TreeNode* leftNode = new TreeNode(stoi(str)); 
			node->left = leftNode; 
			q.push(leftNode); 
		}
		
		getline(s, str, ','); 
		if(str == '#')
			node->right = null; 
		else
		{
			TreeNode* rightNode = new TreeNode(stoi(str)); 
			node->right = rightNode; 
			q.push(rightNode); 
		}
	}
	
	return root; 
	}
*/

// Striver's Code 
/*
void serialize(TreeNode* root, vector<int> &serialized_res, queue<TreeNode*> node_queue)
{
	if(root == nullptr)
		return ""; 
		
	node_queue.push(root); 
	
	while(!node_queue.empty())
	{
		TreeNode *currNode = node_queue.front(); 
		node_queue.pop(); 
		
		if(currNode == NULL)
			serialized_res.push_back(-1); 
			
		else 
			serialized_res.push_back(currNode->data); 
			
		if(currNode != nullptr)
		{
			node_queue.push(currNode->left); 
			node_queue.push(currNode->right); 
		}
	}
}

// Decodes your encoded data tree 
TreeNode *deserialize(string data)
{
	if(data.size()==0)
		return NULL; 
	stringstream s(data); 
	string str; 
	getline(s, str, ''); 
	TreeNode *root = new TreeNode(stoid(str)); 
	queue<TreeNode*> q; 
	q.push(root); 
	
	while(!q.empty())
	{
		TreeNode *node = q.front(); 
		q.pop(); 
		
		getline(s, str, ','); 
		if(str == "#")
		{
			node->left = NULL; 
		}
		
		else 
		{
			TreeNode *leftNode = new TreeNode(stoi(str)); 
			node->left = leftNode; 
			q.push(leftNode); 
		}
		
		getline(s, str, ','); 
		
		if(str == "#")
		{
			node->right = NULL; 
		}
		
		else 
		{
			TreeNode* rightNode = new TreeNode(stoi(str)); 
			node->right = rightNode; 
			q.push(rightNode); 
		}
	}
	
	return root; 
}



// Converting an array to a level-wise tree data structure 
// void deserialize(vector<int> &serialized_res, int n, int idx, TreeNode* new_root)
// {
// 	
	// new_root = new TreeNode(serialized_res[idx]); 
// 	
	// if((2*idx+1 < n) or (serialized_res[2*idx+1] != -1))
		// new_root->left = deserialize(serialized_res, n, 2*idx+1); 
// 	
	// if((2*idx+2 < n) or (serialized_res[2*idx+2] != -1))
		// new_root->right = deserialize(serialized_res, n, 2*idx+1);
// 		
	// else 
		// return;
// 
// }
// 
*/

// Function to insert a new node in Binary Tree 
void solve()
{   
	// Do Something
	// Construct the tree 
	unordered_map<TreeNode*, bool> isLeafMap; 
	vector<int> serialized_res; 
	queue<TreeNode*> node_queue; 
	
	TreeNode* root = new TreeNode(10);
	isLeafMap[root] = false;  
	
	root->left = new TreeNode(20); 
	isLeafMap[root->left] = false; 
	
	root->left->left = new TreeNode(40);
	isLeafMap[root->left->left] = true; 
	 
	root->left->right = new TreeNode(50); 
	isLeafMap[root->left->right] = true; 
	
	root->right = new TreeNode(30); 
	isLeafMap[root->right] = false; 
	 
	root->right->right = new TreeNode(60); 
	isLeafMap[root->right->right] = true; 
	
	serialize(root, serialized_res, node_queue);
	
	for(auto &x: serialized_res)
		cout << x << " "; 
		
	cout << endl; 
	
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