#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      data=k;
      left=right=NULL;
  }
};

int findLCA(int n1, int n2, unordered_map<int, int> parent, unordered_map<int, int> depth)
{
	// BASE CASE 
	if(n1==n2)
		return n1;
	else if(parent[n1] == parent[n2])
		return parent[n1];
		
	
	if(depth[n1] > depth[n2])
		return findLCA(parent[n1], n2, parent, depth);
		
	else if(depth[n1] < depth[n2])
		return findLCA(n1, parent[n2], parent, depth);
			
	else 
		return findLCA(parent[n1], parent[n2], parent, depth);		
}

int createParent(int n1, int n2, int n, Node *root, unordered_map<int, int> parent, unordered_map<int, int> depth)
{
	// Do something
	// Perform level order traversal and store the parents on the go 
	queue<Node*> q;
	int level = 0;
	q.push(root);
	parent[root->data] = 0;
	depth[root->data] = level;
	level++;
	
	while(!q.empty())
	{
		Node *node = q.front();
		q.pop();
		
		if(node->left)
		{
			q.push(node->left);
			parent[node->left->data]=node->data;
			depth[node->left->data]=level;
		}
		
		if(node->right)
		{
			q.push(node->right);
			parent[node->right->data]=node->data;
			depth[node->right->data]=level;
		}
		
		level++;
	}
	
	return findLCA(n1, n2, parent, depth);
}

int main()
{
	int n=0;
	Node *root=new Node(10);
	n++;
	root->left=new Node(20);
	n++;
	root->right=new Node(30);
	n++;
	root->right->left=new Node(40);
	n++;
	root->right->right=new Node(60);
	n++;
	root->right->left->left=new Node(50);
	n++;
	root->right->right->right=new Node(70);
	n++;
	
	// Input the 2 nodes for which LCA has to be derived
	int n1, n2;
	cin >> n1 >> n2;
	unordered_map<int, int> parent, depth;
	cout << createParent(n1, n2, n, root, parent, depth) << endl;
	
}