/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};


info solve(TreeNode* root, int &ans) {
    // Base Case: An empty node is a BST of size 0
    if (!root) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // BST Validation Logic
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    // Update the global maximum size if the current subtree is a valid BST
    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    
    return currNode;
}

int largestBST(TreeNode* root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}