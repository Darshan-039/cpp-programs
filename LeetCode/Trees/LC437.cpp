// Leetcode Problem 437: Path Sum III



// Approach -1: Using Prefix Sum and HashMap (without initializing m[0] = 1)


class Solution {
private:
    void solve(TreeNode* root, int targetSum, long long currSum, int &count, unordered_map<long long, int> &m) {
        if (!root) return;

        currSum += root->val;

        // 1. Check if the path starting from the ROOT matches targetSum
        if (currSum == targetSum) {
            count++;
        }

        // 2. Check if any sub-path (starting somewhere below root) matches targetSum
        if (m.count(currSum - targetSum)) {
            count += m[currSum - targetSum];
        }

        m[currSum]++; // Add current sum to map

        solve(root->left, targetSum, currSum, count, m);
        solve(root->right, targetSum, currSum, count, m);

        m[currSum]--; // Backtrack
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long, int> m;
        // m[0] = 1;  <-- Removed as requested
        
        solve(root, targetSum, 0, count, m);
        return count;
    }
};






// Approach - 2: Using Prefix Sum and HashMap (with initializing m[0] = 1)

class Solution {

private:

    // Using long long to prevent overflow

    void solve(TreeNode* root, int targetSum, long long currSum, int &count, unordered_map<long long, int> &m) {

        if (!root) return;



        currSum += root->val;



        // If (currSum - targetSum) exists, those are our valid paths

        if (m.count(currSum - targetSum)) {

            count += m[currSum - targetSum];

        }



        m[currSum]++; // Add current sum to map



        solve(root->left, targetSum, currSum, count, m);

        solve(root->right, targetSum, currSum, count, m);



        m[currSum]--; // Backtrack

    }



public:

    int pathSum(TreeNode* root, int targetSum) {

        int count = 0;

        unordered_map<long long, int> m;

        m[0] = 1; // Base case: a sum of 0 is always "seen" once

        

        solve(root, targetSum, 0, count, m);

        return count;

    }

};