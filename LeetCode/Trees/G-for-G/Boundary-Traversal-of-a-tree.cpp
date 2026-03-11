/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
private:
void TraverseLeft(Node* root, vector<int> &ans) {
    if(!root || (!root -> left && !root -> right)) return;

    ans.push_back(root -> data);

    if(root -> left) TraverseLeft(root -> left,ans);
    else TraverseLeft(root -> right,ans);

    return;
}

void TraverseLeaf(Node* root, vector<int> &ans) {
    if(!root) return;

    if(!root -> left && !root -> right) {
        ans.push_back(root -> data);
        return;
    }

    TraverseLeaf(root -> left,ans);
    TraverseLeaf(root -> right,ans);

}

void TraverseRight(Node* root, vector<int> &ans) {
    if(!root || (!root -> left && !root -> right)) return;

    if(root -> right) TraverseRight(root -> right,ans);
    else TraverseRight(root -> left,ans);

    ans.push_back(root -> data);
}


public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        //left part print/store
        TraverseLeft(root->left, ans);
        
        //traverse Leaf Nodes
        
        //left subtree
        TraverseLeaf(root->left, ans);
        //right subtree
        TraverseLeaf(root->right, ans);
        
        //traverse right part
        TraverseRight(root->right, ans);
        
        return ans;
    }
};
