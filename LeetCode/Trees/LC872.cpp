// Leetcode 872. Leaf-Similar Trees



#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    // 🔹 Function to collect all leaf nodes in left-to-right order
    void solve(TreeNode* root, vector<int>& leaves) {
        if (!root) return;

        // ✅ If it's a leaf node (no children)
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
            return;
        }

        // Traverse left subtree
        solve(root->left, leaves);

        // Traverse right subtree
        solve(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;

        // Get leaf sequence of both trees
        solve(root1, seq1);
        solve(root2, seq2);

        // Compare both sequences
        return seq1 == seq2;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    /*
        Tree 1:
              3
             / \
            5   1
           / \ / \
          6  2 9  8
            / \
           7   4

        Leaf sequence: [6, 7, 4, 9, 8]
    */

    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);

    /*
        Tree 2:
              3
             / \
            5   1
           /   / \
          6   7   4
             / \
            9   8

        Leaf sequence: [6, 7, 4, 9, 8]
    */

    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->right->left = new TreeNode(7);
    root2->right->right = new TreeNode(4);
    root2->right->left->left = new TreeNode(9);
    root2->right->left->right = new TreeNode(8);

    // 🔹 Call function
    bool ans = obj.leafSimilar(root1, root2);

    if(ans) cout << "Leaf sequences are SAME\n";
    else cout << "Leaf sequences are DIFFERENT\n";

    return 0;
}