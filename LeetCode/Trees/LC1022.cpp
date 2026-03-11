// Leetcode 1022. Sum of Root To Leaf Binary Numbers





// Approach - 1: Using String

// class Solution {
// public:

//     void solve(TreeNode* root, string& temp, int& ans) {
//         if(!root) return;

//         temp.push_back(root -> val + '0');

//         if(!root -> left && !root -> right) {
//             int num = stoi(temp, nullptr, 2);
//             ans += num;
//             temp.pop_back();
//             return;
//         }

//         solve(root->left, temp, ans);
//         solve(root->right, temp, ans);

//         temp.pop_back();
//     }

//     int sumRootToLeaf(TreeNode* root) {
//         int ans = 0;
//         string temp = "";
        
//         solve(root, temp, ans);

//         return ans;
//     }
// };












// Approach - 2: Using Integer

class Solution {
public:

    int solve(TreeNode* root, int currentSum) {
        if(!root) return 0;

        currentSum = currentSum * 2 + root -> val;

        if(!root -> left && !root -> right) return currentSum;

        return solve(root -> left, currentSum) + solve(root -> right, currentSum);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};