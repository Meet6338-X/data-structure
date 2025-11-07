#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void preorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl
         << "Inorder traversal: ";
    inorder(root);
    cout << endl
         << "Post Order traversal: ";
    postorder(root);
}

// copy
//  // Node structure for the binary tree
//  struct Node
//  {
//      int data;
//      Node *left;
//      Node *right;
//      // Constructor to initialize
//      // the node with a value
//      Node(int val) : data(val), left(nullptr), right(nullptr) {}
//  };
// // Solution class containing traversal functions
// class Solution
// {
// public:
//     // Function to perform preorder traversal
//     // of the tree and store values in 'arr'
//     void preorder(Node *root, vector<int> &arr)
//     {
//         // If the current node is NULL
//         // (base case for recursion), return
//         if (root == nullptr)
//         {
//             return;
//         }
//         // Push the current node's
//         // value into the vector
//         arr.push_back(root->data);
//         // Recursively traverse
//         // the left subtree
//         preorder(root->left, arr);
//         // Recursively traverse
//         // the right subtree
//         preorder(root->right, arr);
//     }

//     // Function to initiate preorder traversal
//     // and return the resulting vector
//     vector<int> preOrder(Node *root)
//     {
//         // Create an empty vector to
//         // store preorder traversal values
//         vector<int> arr;
//         // Call the preorder traversal function
//         preorder(root, arr);
//         // Return the resulting vector
//         // containing preorder traversal values
//         return arr;
//     }
// };

// copy
//  // Definition for a binary tree node
//  struct TreeNode
//  {
//      int val;
//      TreeNode *left, *right;
//      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  };
// // Solution class with postorder function
// class Solution
// {
// public:
//     void postorderTraversal(TreeNode *root, vector<int> &result)
//     {
//         // Base case: if node is null
//         if (!root)
//             return;

//         // Traverse left subtree
//         postorderTraversal(root->left, result);

//         // Traverse right subtree
//         postorderTraversal(root->right, result);

//         // Add current node value
//         result.push_back(root->val);
//     }
// };
// // Main function
// int main()
// {
//     // Build tree:    1
//     //              /   \
//     //             2     3
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);

//     // Object of solution
//     Solution sol;
//     vector<int> result;

//     // Call postorder traversal
//     sol.postorderTraversal(root, result);

//     // Print result
//     for (int val : result)
//         cout << val << " ";
//     return 0;
// }