/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
private: 
    pair<bool,int> sum(Node* root) {
        if(!root) {
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        
        if(!root->left && !root-> right) {
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left = sum(root -> left);
        pair<bool,int> right = sum(root -> right);
        
        // creating three conditions
        bool condL = left.first;
        bool condR = right.first;
        bool condEq = root->data == left.second + right.second;
        
        pair<bool,int> ans;
        ans.second = 2*root-> data;
    
        if(condL && condR && condEq) ans.first = true;
        else ans.first = false;
        
        return ans;
    }
public:
    bool isSumTree(Node* root) {
        // Your code here
        return sum(root).first;
    }
};