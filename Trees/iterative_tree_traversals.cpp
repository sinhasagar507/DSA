/* 
Problem Statement: Given a binary tree, print its inorder traversal using a loop 

Applications: Refer this reddit post - https://www.reddit.com/r/cscareerquestions/comments/ntvtzq/do_you_use_recursion_in_your_projects_at_work/

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

// Time Complexity: O(n)
// Space Complexity: O(n)
void iterativeInorderTraversal(TreeNode* root)
{
	stack<TreeNode*> st; 
	TreeNode* curr = root; 
	
	while(!st.empty() or curr!=nullptr)
	{
		while(curr != nullptr)
		{
			st.push(curr); 
			curr = curr->left; 
		}
		
		curr = st.top(); 
		cout << curr->data << " "; 
		st.pop(); 
		
		curr = curr->right; 
	}
}

// Time Complexity: O(n)
// Space Complexity: O(n)
void iterativePreorderTraversal(TreeNode *root)
{
	if(root == nullptr)
		return; 
		
	stack<TreeNode*> st;
	st.push(root);  
	
	while(st.empty() == false)
	{
		TreeNode* curr = st.top(); 
		cout << curr->data << " "; 
		st.pop(); 
		
		if(curr->right != nullptr)
			st.push(curr->right); 
			
		if(curr->left != nullptr)
			st.push(curr->left); 
	}
}

// Time Complexity: O(n). Space Complexity: O(h). Less Space Complexity than the earlier iterative method of preorder traversal 
void iterativePreorderTraversal(TreeNode *root) {
    if (root == nullptr)
        return;  // If the tree is empty, return

    stack<TreeNode*> st;  // Create a stack to store tree nodes
    st.push(root);  // Push the root node onto the stack

    TreeNode* curr = root;  // Initialize a pointer to the current node

    while (!st.empty()) {
        while (curr != nullptr) {
            cout << curr->key;  // Print the value of the current node

            if (curr->right != nullptr)
                st.push(curr->right);  // Push the right child onto the stack if it exists

            curr = curr->left;  // Move to the left child
        }

        curr = st.top();  // Get the top node from the stack
        st.pop();  // Pop the top node as it has been processed

        // At this point, the left subtree of the current node has been traversed.
        // Now, the algorithm moves to the right subtree of the current node in the next iteration.
    }
}

/*
Code Under Process: to be completed later 
void IterativePostOrderTraversal()
{
	stack<TreeNode*> st; 
	TreeNode* curr = root;
	st.push(curr);  
	
	while(!st.empty() or curr != nullptr)
	{
		curr = st.top(); 
		while(curr != nullptr)
		{
			if(curr->right)
				st.push(curr->right); 
				
			if(curr->left)
				st.push(curr->left); 
				
			curr = curr->left; 
		}
		
		if(curr == nullptr)
		{
			curr = st.top(); 
			
			if(curr->right)
			{
				curr = curr->right; 
				continue; 
			}
			// cout << curr->data << " ";
			
			// if(!curr->)
			// st.pop();  
			// curr = curr->right; 
		}
		
		if(!curr->right)
		{
			cout << curr->data << " "; 
			st.pop(); 
		}
		curr = st.top(); 
		st.pop(); 
		cout << curr->key << " "; 
		
		curr = curr->right; 
		
	}
}
*/

void solve()
{   
	// Do Something 
	TreeNode *root = new TreeNode(10); 
	root->left = new TreeNode(20); 
	root->left->left = new TreeNode(30); 
	root->left->left->left = new TreeNode(40); 
	root->left->right = new TreeNode(60); 
	root->left->right->left = new TreeNode(80); 
	root->left->right->left->right = new TreeNode(100); 

	cout << "Inorder Traversal: "; 
	iterativeInorderTraversal(root); 
	
	cout << "\n"; 
	
	cout << "Preorder Traversal: ";
	iterativePreorderTraversal(root); 
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