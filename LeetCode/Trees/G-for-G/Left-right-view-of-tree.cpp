/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
private:
    void solve(Node* root, vector<int> &ans, int level) {
        if(!root) return;
        
        if(level == ans.size()) ans.push_back(root -> data);
        
        solve(root -> left,ans,level+1);
        solve(root -> right,ans,level+1);


        // Swap these two lines to get the right view of the tree
        // Swap these two lines to get the right view of the tree
        // Swap these two lines to get the right view of the tree
        // Swap these two lines to get the right view of the tree
        // Swap these two lines to get the right view of the tree

    }
 public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        int level = 0;
        
        solve(root,ans,level);
        
        return ans;
    }
};





