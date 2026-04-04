// Leetcode 1372. Longest ZigZag Path in a Binary Tree



#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:

    int maxPath = 0; // stores maximum zigzag length

    // 🔹 Recursive function
    // left  → length of path when last move was LEFT
    // right → length of path when last move was RIGHT
    void solve(TreeNode* root, int left, int right) {
        if(!root) return;

        // ✅ Update global maximum
        maxPath = max({ maxPath, left, right });

        // 🔽 Move to left child
        // If we go left → previous direction must be right
        solve(root->left, right + 1, 0);

        // 🔽 Move to right child
        // If we go right → previous direction must be left
        solve(root->right, 0, left + 1);
    }

    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        return maxPath;
    }
};


// 🔥 MAIN FUNCTION (Sample Input)
int main() {
    Solution obj;

    /*
        Example Tree:
                1
               / \
              2   3
               \   \
                4   5
               /
              6
               \
                7

        One ZigZag path:
        1 → 2 → 4 → 6 → 7
        Directions: L → R → L → R
        Length = 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(6);
    root->left->right->left->right = new TreeNode(7);

    root->right->right = new TreeNode(5);

    // 🔹 Call function
    int ans = obj.longestZigZag(root);

    cout << "Longest ZigZag Path Length: " << ans << endl;

    return 0;
}