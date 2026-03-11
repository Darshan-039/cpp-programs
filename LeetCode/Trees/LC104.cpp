/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        if(root == NULL) return -1;
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        int ans = max(left , right) + 1;
        return ans;
        
    }
};




// for return height in terms of number of nodes
// return 0

// for return height in trems of number of edges
// return -1