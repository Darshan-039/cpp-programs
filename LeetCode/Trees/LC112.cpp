/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1. Base Case: Empty tree has no path
        if (!root) return false;

        // 2. Check if we are at a Leaf Node
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // 3. Recursive Call: Subtract current value and check children
        // We use OR (||) because if either the left or right subtree 
        // has a valid path, the answer is true.
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};









// Approach - 2
// Queue stores {current_node, sum_of_ancestors}
std::queue<std::pair<TreeNode*, int>> q;
q.push({root, 0}); // Note: we push 0 because root has no ancestors

while (!q.empty()) {
    auto [currNode, parentSum] = q.front();
    q.pop();

    // 1. ADD current node's value to the parent's sum here
    int currSum = parentSum + currNode->val;

    // 2. CHECK if this leaf matches the target
    if (!currNode->left && !currNode->right) {
        if (currSum == targetSum) return true;
    }

    // 3. PUSH children with the updated sum
    if (currNode->left) {
        q.push({currNode->left, currSum});
    }
    if (currNode->right) {
        q.push({currNode->right, currSum});
    }
}















// Approach - 3
while (!q.empty()) {
    auto [currNode, currSum] = q.front();
    q.pop();

    // Check if we've reached a leaf with the target sum
    if (!currNode->left && !currNode->right && currSum == targetSum) {
        return true;
    }

    // When moving to children, we "add" their value to the parent's sum
    if (currNode->left) {
        // This is where 'currSum += child->val' conceptually happens
        q.push({currNode->left, currSum + currNode->left->val});
    }
    if (currNode->right) {
        q.push({currNode->right, currSum + currNode->right->val});
    }
}