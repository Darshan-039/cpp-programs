// Leetcode 404. Sum of Left Leaves


#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to calculate sum of all left leaf nodes
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;

        int sum = 0;

        // Check left child
        if (root->left) {
            // If left child is a leaf node, add its value
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            } else {
                // Otherwise, recurse on left subtree
                sum += sumOfLeftLeaves(root->left);
            }
        }

        // Always recurse on right subtree
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};


// Build tree using level-order input
TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.size() == 0 || nodes[0] == "null") return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}


// Main function
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter nodes in level order (use 'null' for empty):\n";
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Solution obj;
    int result = obj.sumOfLeftLeaves(root);

    cout << "Sum of left leaves: " << result << endl;

    return 0;
}