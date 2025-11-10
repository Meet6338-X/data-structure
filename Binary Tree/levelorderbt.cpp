#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Queuee
{
    Node *st[50];
    int front, rear, x;

public:
    Queuee()
    {
        front = -1;
        rear = -1;
        x = sizeof(st) / sizeof(st[0]);
    }

    void enqueue(Node *val)
    {
        if (rear == x - 1)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        st[rear] = val;
    }

    Node *dequeue()
    {
        if (front == -1 || front > rear)
        {
            return nullptr;
        }
        Node *temp = st[front];
        front++;
        return temp;
    }

    bool empty()
    {
        return (front == -1 || front > rear);
    }

    Node *frontt()
    {
        if (front == -1 || front > rear)
            return nullptr;
        return st[front];
    }

    int sizei()
    {
        if (front == -1)
            return 0;
        return rear - front + 1;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;

    Queuee q;
    q.enqueue(root);

    while (!q.empty())
    {
        int size = q.sizei();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.dequeue();
            level.push_back(node->data);
            if (node->left)
                q.enqueue(node->left);
            if (node->right)
                q.enqueue(node->right);
        }
        ans.push_back(level);
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(100);
    root->right->right->right = new Node(120);

    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (auto level : result)
    {
        for (auto val : level)
            cout << val << " ";
        cout << endl;
    }
}

// copy
//  #include <iostream>
//  #include <vector>
//  #include <queue>

// using namespace std;

// // TreeNode struct represents
// // a node in a binary tree
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     // Default constructor for TreeNode
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}

//     // Constructor with a value
//     // parameter for TreeNode
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

//     // Constructor with value, left
//     // child, and right child
//     // parameters for TreeNode
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
// public:
//     // Function to perform level-order
//     // traversal of a binary tree
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         // Create a 2D vector to store levels
//         vector<vector<int>> ans;
//         if (root == nullptr)
//         {
//             // If the tree is empty,
//             // return an empty vector
//             return ans;
//         }

//         // Create a queue to store nodes
//         // for level-order traversal
//         queue<TreeNode *> q;
//         // Push the root node to the queue
//         q.push(root);

//         while (!q.empty())
//         {
//             // Get the size of the current level
//             int size = q.size();
//             // Create a vector to store
//             // nodes at the current level
//             vector<int> level;

//             for (int i = 0; i < size; i++)
//             {
//                 // Get the front node in the queue
//                 TreeNode *node = q.front();
//                 // Remove the front node from the queue
//                 q.pop();
//                 // Store the node value
//                 // in the current level vector
//                 level.push_back(node->val);

//                 // Enqueue the child nodes if they exist
//                 if (node->left != nullptr)
//                 {
//                     q.push(node->left);
//                 }
//                 if (node->right != nullptr)
//                 {
//                     q.push(node->right);
//                 }
//             }
//             // Store the current level
//             // in the answer vector
//             ans.push_back(level);
//         }
//         // Return the level-order
//         // traversal of the tree
//         return ans;
//     }
// };

// // Function to print
// // the elements of a vector
// void printVector(const vector<int> &vec)
// {
//     // Iterate through the
//     // vector and print each element
//     for (int num : vec)
//     {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// // Main function
// int main()
// {
//     // Creating a sample binary tree
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//     // Create an instance
//     // of the Solution class
//     Solution solution;
//     // Perform level-order traversal
//     vector<vector<int>> result = solution.levelOrder(root);

//     cout << "Level Order Traversal of Tree: " << endl;

//     // Printing the level order traversal result
//     for (const vector<int> &level : result)
//     {
//         printVector(level);
//     }

//     return 0;
// }
