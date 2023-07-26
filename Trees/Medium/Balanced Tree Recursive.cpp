/* Program to check balanced binary tree */

#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, left
child and right child */
struct TreeNode
{
    int data;
    TreeNode *lchild;
    TreeNode *rchild;
    
    TreeNode(int x)
    {
    	data = x;
    	lchild = rchild = NULL;
    }
};
 
// Always in recursion, first visualize at a conceptual level as to what I need to evaluate 
// Thenevaluate what I would accomplish for each child or succeeding element in a sequence 

pair<bool, int> checkBalance(TreeNode *root)
{
	if(root==NULL)
	{
		pair<bool, int> p = make_pair(true, 0);
		return p;
	}
		
		
	pair<bool, int> leftAns = checkBalance(root->lchild);
	pair<bool, int> rightAns = checkBalance(root->rchild);
	
	bool diff = (abs(leftAns.second - rightAns.second) <= 1);
	
	pair<bool, int> ans;
	if(leftAns.first and rightAns.first and diff)
		ans.first = true;
	
	else
		ans.first = false;
		
	ans.second = max(leftAns.second, rightAns.second)+1;
	
	return ans;
}
 
 
// Driver Code
int main()
{
    TreeNode *root = new TreeNode(10);
    root->lchild = new TreeNode(8);
    root->rchild = new TreeNode(2);
    root->lchild->lchild = new TreeNode(3);
    root->lchild->rchild = new TreeNode(5);
    root->rchild->rchild = new TreeNode(2);
    root->lchild->lchild->lchild = new TreeNode(12);
    
    cout << checkBalance(root).first << endl;
    
    return 0;
}
