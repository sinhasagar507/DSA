/*
Problem Statement: Delete a node from BST 
More details: For gaining a more intuitive perspective behind the workings (and test cases) of these algorithms, refer this article: https://www.youtube.com/watch?v=kouxiP_H5WE
Practical Applications: 
1. Database Management: BSTs are used in database indexing structures. Deleting records from a database involves removing corresponding entries from the BST index 
2. File Management: Deleting files or directories requires removing nodes from the BST representing the file system structure 
3. Dynamic Memory Allocation: BSTs are used in memory management systems, such as dynamic memory allocation and deallocation in programming languages. Deleting 
                              nodes from these data structures involves deleting nodes from the underlying BST 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find the rightmost node in a binary tree
Node* findLastRight(Node* root)
{
    // If the right child of the current node is NULL, it means this node is the rightmost node
    if(root->right == NULL)
        return root; 
        
    // Recursively call the function on the right child to traverse towards the rightmost node
    return findLastRight(root->right); 
}

// Helper Code 
Node* helper(Node* root)
{
	if(root->left == NULL) 
		return root->right; // If there exists a root node return root->right; 
		
	else if(root->right == NULL) 
		return root->left; 
		
	Node* rchild = root->right; 
	Node* lastRight = findLastRight(root->left); 
	lastRight->right = rchild; 
	return root->left; 
}

// Time Complexity: O(height of tree). O(n) if the tree is skewed
// Space Complexity: O(height of tree). O(n) if the tree is skewed 
struct Node* deleteNode(Node* root, int key)
{
	// Check if the root node is NULL
	if(root == NULL) // If there's no root node
	    return NULL; // Return null pointer indicating an empty tree
	
	// If the root node itself is the node to be deleted
	if(root->data == key) // If the root node contains the value to be deleted
	    return helper(root); // Call the helper function to handle deletion, explained in its own details
	
	// Create a dummy pointer to keep track of the root node
	Node* dummy = root; // Now we know for a fact that its not the root node that is to be deleted 
	
	// Loop to find the node to be deleted or its parent node
	while(root != NULL)
	{
	    // Check if the node to be deleted is in the left subtree
	    if(root->data > key) // If the value to delete is smaller than the current node's value
	    {
	        // If the left child of the current node matches the value to be deleted
	        if(root->left != NULL && root->left->data == key)
	        {
	            // Call the helper function to delete the node from the left subtree
	            root->left = helper(root->left); 
	            break; // Exit the loop after the deletion is done
	        }
	        else 
	            root = root->left; // Traverse to the left subtree
	    }
	    else // If the node to be deleted is in the right subtree
	    {
	        // If the right child of the current node matches the value to be deleted
	        if(root->right != NULL && root->right->data == key)
	        {
	            // Call the helper function to delete the node from the right subtree
	            root->right = helper(root->right); 
	            break; // Exit the loop after the deletion is done
	        }
	        else
	            root = root->right; // Traverse to the right subtree
	    }
	}
	
	// Return the root of the modified tree 
	return dummy; 
}

// Function to Build Tree
Node* buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') 
    	return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    stringstream iss(str); // Converts the string into an incoming stringstream object and store all objects in the string vector
    for (string str; iss >> str;) 
    	ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue. I need a queue because I need those nodes anyway
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) // Why would I even take it to the next iteration? No, I won't do so
        	break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        root1 = deleteNode(root1, k);
        vector<int> v;
        inorder(root1, v);
        for (auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

