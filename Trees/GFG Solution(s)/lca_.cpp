// This solution requires one traversal and theta(h) extra space for the recursive traversal 
// Assume that both n1 and n2 exist in this tree. Doesn't give correct result when only n1 or n2 exists

/*
Idea: We do normal recursive traversal, we have the following cases for every node 
      a. If it is same as n1 or n2
      b. If one of the subtrees contains n1 and the other contains n2
      c. If one of the subtrees contains both n1 and n2 
      d. If none of the subtrees contain any of n1 and n2

*/
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

Node *lca(Node *root, int n1, int n2){
    if(root==NULL)return NULL;
    if(root->key==n1||root->key==n2)
        return root;
    
    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);
    
    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}


int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=10,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
}