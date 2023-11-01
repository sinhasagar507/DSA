/* 
Construct a binary tree and evaluate its height 
*/

#include <bits/stdc++.h> 
using namespace std; 

struct TreeNode { 
	int data; 
	TreeNode *lchild, *rchild; 
	TreeNode(int x) 
	{ 
		data = x; 
		lchild = rchild = NULL;
	} 
}; 

// Converting an array to a level-wise tree data structure 
TreeNode *treeConstruct(vector<int> v, int n, int index, TreeNode *root) 
{ 
	
	if(index<n)
	{
		TreeNode *temp = new TreeNode(v[index]);
		root = temp;
		root->lchild = treeConstruct(v, n, 2*index+1, root->lchild);
		root->rchild = treeConstruct(v, n, 2*index+2, root->rchild);
	}
	
	return root;
} 


// Print Inorder Tree Traversal 
void printInorder(TreeNode *root)
{
	if(root==NULL)
		return;
		
	printInorder(root->lchild);
	cout << root->data << " ";
	printInorder(root->rchild);
}
	 

int main() 
{ 
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i=0; i<n; i++)
		cin>>v[i];
		
	TreeNode *root = NULL;
	root = treeConstruct(v, n, 0, root);
	printInorder(root);
	cout << endl;
} 


