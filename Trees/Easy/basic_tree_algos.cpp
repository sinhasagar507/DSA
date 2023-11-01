/* 
	Binary Tree
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

queue<TreeNode*> q;

// Converting an array to a level-wise tree
// Recursive code, always practice using a recursive call stack. Time Complexity is O(n) and space complexity is O(h)
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


// Keep all codes here. Useful for referring in short glances 

// 	Find and delete deepest rightmost node
//  Deleting the node towards the end 


// First find the node with the given key 
// Then pass root node and key value to a function. Find the deepest node to  
void deleteRightDeep(TreeNode *root, int x)
{	
	q.push(root); 	
	if(root->data == x)
	{	
		q.pop();
		root == NULL;
		delete root;
		return;
	}
	
	else
	{
		while(!q.empty())
		{
			TreeNode *temp = q.front();
			q.pop();
			
			if(temp->rchild)
			{	
				temp = temp->rchild;
				if(temp->data == x)
				{
					temp = NULL;
					delete temp;
					return;
				}
				
				else
					q.push(temp);
			}
			
			if(temp->lchild)
			{
				temp = temp->lchild;
				if(temp->data == x)
				{
					temp = NULL;
					delete temp;
					return;
				}
				
				else
					q.push(temp);
			}
		}
	}
}


// Replace the element to be deleted with the value of the deepest rightest element 
// Write a function block for that. Do any tree traversal and replace the node 
// Since there is no particular mechanism to delete from a binary tree, we devise a particular mechanism and then delete from it 

// Print Inorder Tree Traversal. Time Complexity is O(n) and space complexity is O(h)
void printInorder(TreeNode *root)
{
	if(root==NULL)
		return;
		
	printInorder(root->lchild);
	cout << root->data << " ";
	printInorder(root->rchild);
}
	 
	
// Algorithm for Level-Order Traversal. Remember, a complete binary tree would always have a left sub-child first. Time Complexity is O(n), whereas space complexity of this solution is O(w), where w is the width of this tree 
/*
1. Construct a tree and initialize an empty queue
2. Store the root of tree in the queue
3. Loop while the queue is not empty
4. Print the queue's front, pop queue and then insert left and right children(if they exist)
5. Repeat the process and print all the nodes 

// Level-Order Traversal Line by Line 
// If I think clearly, I already have the answer. The idea is to use level-order as you do. Just pop and run a for loop within a while loop. Time Complexity of that solution would be O(hw)

// Height of a Tree. Its solution is O(h)
int getHeight(TreeNode *root)
{
	if(root==NULL)
		return 0;
		
	else
		return (1+max(getHeight(root->lchild), getHeight(root->rchild)));
}

// Print Nodes at Kth distance. My Solution 
/*
void printKthNode(TreeNode *root, int cnt, int k)
{
	// Base Cases 
	if(root==NULL)
		return;
		
	if(k==0)
		cout << root->data << endl;
	
	// Self-Work 
	else if(cnt == k)
	{
		cout << root->data << " ";
		return;
	}
		
	// Recursive Intuition 
	else
	{
		printKthNode(root->lchild, cnt+1, k);
		printKthNode(root->rchild, cnt+1, k);
	}	
}
*/

// GFG Solution. Both approaches are almost same 
void printKthNode(TreeNode *root, int k)
{
	// Base Case
	if(root==NULL)
		return;
		
	// Self-Work 
	if(k==0)
		cout << root->data << endl;
		
		
	// Recursive Intuition 
	else
	{
		printKthNode(root->lchild, k-1);
		printKthNode(root->rchild, k-1);
	}
}

// Count Number of Nodes in a Binary Tree or Size of a Binary Tree
// The solution is much like earlier. Like calculating height of a binary tree. Even tree traversals can be used to accomplish this 
// Calculating Maximum Element in a Binary Tree. The solution is much like calculating height
int getMax(TreeNode *root)
{
	if(root==NULL)
		return INT_MIN;
		
	else
		return max(root->data, max(getMax(root->lchild), getMax(root->rchild)));
}

// Level Order Traversal takes theta(n) TC and complexity 


// Print Left View of Binary Tree
void printLeftView(TreeNode *root, int cnt, unordered_set<int> &s)
{
	if(root==NULL)
		return;
		
		
	if(s.find(cnt) == s.end())
	{
		cout << root->data << " ";
		s.insert(cnt);
	}
	
	printLeftView(root->lchild, cnt+1, s);
	printLeftView(root->rchild, cnt+1, s);
}


//  Converting a BT to a DLL - The complete recursive intuition
/* 
TreeNode *BTtoDLL(TreeNode *root)
{
	// Base Case
	if(root == NULL)
		return root;
	
	TreeNode *prev = NULL;
	
	// Recursive Intuition 
	TreeNode *head = BTtoDLL(root->left); 
	if(prev==NULL)
		root = head;
	
	else
	{
		root->lchild = prev;
		prev->rchild = root;
		
	}
	prev = root;
	BTtoDLL(root->right);
	
	// Self-Work 
	return head;
}
*/

// Print Left view of Binary Tree by GFG
int maxLevel=0;
/*
void printLeft(Node *root, int level)
{
	if(root==NULL)
		return;
	
	if(maxLevel < level)
	{
			// We try increasing the value of level 
			cout << root->data << " ";
			maxLevel = level;
	}
	
	printLeft(root->lchild, level+1);
	printLeft(root->rchild, level+1);
} 
*/

// Conversion of BT to doubly LL 

int main() 
{ 
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_set<pair<int, int> s;
	
	for(auto it:s)
		cout<< it.first << " " << it.second;
	
	for(int i=0; i<n; i++)
		cin>>v[i];
		
	// TreeNode *root = NULL;
	// root = treeConstruct(v, n, 0, root);
	// printInorder(root);
	
	
	
	cout << endl;
	
	// printKthNode(root, 3);
	
	// Get height of binary tree first 
	// int height = getHeight(root);
	// cout << height << endl;
	// printLeftView(root, 0, s);

} 


// Constructing a tree from Inorder and PreOrder Traversals. Perform a similar from PostOrder and InOrder Traversals
/*
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  

int preIndex=0;
Node *cTree(int in[],int pre[],int is,int ie){
    if(is>ie)return NULL;
    Node *root=new Node(pre[preIndex++]);
    
    int inIndex;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex=i;
            break;
        }
    }
    root->left=cTree(in, pre, is, inIndex-1);
    root->right=cTree(in, pre, inIndex+1, ie);
    return root;
}

int preIndex=0;
Node *cTree(int pre[], int post[], int is, int ie)
{
	Node *root = new Node(pre[preIndex++]);
	
	int index = 0;
	for(int i=is; i<=ie; i++)
	{
		if(post[i] == root->key)
		{
			index = i;
			break;
		}
	}
	
	root->lchild = cTree(pre, post, );
	root->rchild = cTree(pre, preIndex+1, ie);
	return root;
}




int main() {
	
	int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};
	int n=sizeof(in)/sizeof(in[0]);
	Node *root=cTree(in, pre, 0, n-1);
	inorder(root);
}
*/

