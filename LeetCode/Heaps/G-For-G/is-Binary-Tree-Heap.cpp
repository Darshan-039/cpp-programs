#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // 🔹 Count total number of nodes in the tree
    // Time Complexity: O(n)
    int countNodes(Node* root) {
        if (!root) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // 🔹 Check if tree is Complete Binary Tree (CBT)
    bool isCBT(Node* root, int index, int cnt) {
        if (!root) return true;

        // If index exceeds total nodes → gap exists → not CBT
        if (index >= cnt) return false;

        // Check left and right subtree
        bool left = isCBT(root->left, 2 * index + 1, cnt);
        bool right = isCBT(root->right, 2 * index + 2, cnt);

        return left && right;
    }

    // 🔹 Check Max Heap property
    bool MaxOrder(Node* root) {
        // Leaf node or empty → valid heap
        if (!root || (!root->left && !root->right)) return true;

        // Only left child exists
        if (!root->right) {
            return (root->data >= root->left->data) && MaxOrder(root->left);
        }

        // Both children exist
        bool leftSubtreeOk = MaxOrder(root->left);
        bool rightSubtreeOk = MaxOrder(root->right);

        bool currentOk =
            (root->data >= root->left->data &&
             root->data >= root->right->data);

        return leftSubtreeOk && rightSubtreeOk && currentOk;
    }

    // 🔹 Main function to check if Binary Tree is Heap
    bool isHeap(Node* tree) {
        int totalCount = countNodes(tree);

        return isCBT(tree, 0, totalCount) && MaxOrder(tree);
    }
};


// 🔥 Helper function to build tree (Level Order Input)
// Input: -1 means NULL
Node* buildTree() {
    cout << "Enter root value (-1 for NULL): ";
    int val;
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        cin >> leftVal;

        if (leftVal != -1) {
            temp->left = new Node(leftVal);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        cin >> rightVal;

        if (rightVal != -1) {
            temp->right = new Node(rightVal);
            q.push(temp->right);
        }
    }

    return root;
}


// 🔥 MAIN FUNCTION
int main() {
    Solution sol;

    // Build tree from user input
    Node* root = buildTree();

    // Check if it is a Heap
    if (sol.isHeap(root)) {
        cout << "The binary tree is a Max Heap ✅" << endl;
    } else {
        cout << "The binary tree is NOT a Max Heap ❌" << endl;
    }

    return 0;
}