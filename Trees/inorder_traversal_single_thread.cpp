// Utility function to find leftmost node
// in a tree rooted with N
// In a similar manner, postorder traversal and reverse inorder traversal is aided by double ulta thread 
Node* leftMost(Node *N)
{
    if (N == NULL)
        return NULL;

    while (N->left != NULL)
        N = N->left;

    return N;
}

// Function to do inorder traversal in a 
// threaded binary tree

void inOrder(Node *root)
{
    // Find leftmost node of the root node
    Node *cur = leftmost(root);
    
    // Until the complete tree is traversed
    while (cur != NULL)
    {
        print cur->data;

        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rightThread)
            cur = cur->right;
        // Else go to the leftmost child in 
        // right subtree    
        else 
            cur = leftmost(cur->right);
    }
}