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

void inorderTraversal(TreeNode* root)
{
	if(root == nullptr)
		return; 
		 
	inorderTraversal(root->left); 
	cout << root->data << " ";
	inorderTraversal(root->right); 
}

TreeNode* prevNode = nullptr; 
TreeNode* head = nullptr; 

// function to convert binary tree to a doubly linked list via inorder traversal 
// Time Complexity: O(n)
// Auxiliary Space Complexity: O(1) 
TreeNode* treeToLinkedList(TreeNode* node)
{
	if(node == nullptr)
		return nullptr; 
		
	treeToLinkedList(node->left);
	
	if(prevNode == nullptr)
	{
		node->left = prevNode; 
		head = node; 
		prevNode = node; 
	}
	
	else 
	{
		prevNode->right = node; 
		node->left = prevNode; 
		prevNode = node; 
	}
	
	treeToLinkedList(node->right); 
	return head; 
}

// Print forward the elements of the doubly linked list 
void printForward(TreeNode* head)
{
	TreeNode* curr = head; 
	
	cout << "Forward: ";
    while (curr != nullptr) 
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << "\n";
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
	inorderTraversal(root);
	cout << "\n";  
	
	TreeNode* llHead = treeToLinkedList(root); 
	printForward(llHead); 
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