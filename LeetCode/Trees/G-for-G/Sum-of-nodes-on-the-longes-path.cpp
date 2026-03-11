/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
private:
void solve(Node* root, int sum, int &maxSum, int length, int &maxLen) {
    if(!root) {
        if(length > maxLen) {
            maxLen = length;
            maxSum = sum;
        }
        else if(length == maxLen) {
            maxSum = max(maxSum, sum);
        }
        return;
    }
    
    sum += root -> data;

    solve(root->left,sum,maxSum,length+1,maxLen);
    solve(root->right,sum,maxSum,length+1,maxLen);
}
public:
    int sumOfLongRootToLeafPath(Node *root) {
        int length = 0;
        int maxLen = 0;

        int sum = 0;
        int maxSum = 0;

        solve(root,sum,maxSum,length,maxLen);

        return maxSum;
    }
};