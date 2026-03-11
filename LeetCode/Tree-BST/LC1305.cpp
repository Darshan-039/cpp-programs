// Leetcode 1305. All Elements in Two Binary Search Trees




// Approach - 1: Inorder Traversal + Merge Two Sorted Array
void inorder(TreeNode* root, vector<int> &arr) {
    if(!root) return;

    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Merge both array
    int n = bst1.size();
    int m = bst2.size();

    vector<int> ans;
    int i=0,j=0;
    
    while(i<n && j<m) {
        if(bst1[i] < bst2[j]) ans.push_back(bst1[i++]);
        else ans.push_back(bst2[j++]);
    }   
    
    while(i<n) ans.push_back(bst1[i++]);
    
    while(j<m) ans.push_back(bst2[j++]);
    


    return ans; 
}








// Approach - 2: Convert BST to Sorted Doubly Linked List + Merge Two Sorted Linked List
class Solution {
public:
    void convertToSortedDLL(TreeNode* root, TreeNode* &head) {
        if (!root) return;
        
        // 1. Process Right Subtree
        convertToSortedDLL(root->right, head);
        
        // 2. Link current node to the head of the list already built
        root->right = head;
        if (head) head->left = NULL; 
        
        // 3. Move head to the current node
        head = root;
        
        // 4. Process Left Subtree
        convertToSortedDLL(root->left, head);
    }

    vector<int> mergeToVector(TreeNode* l1, TreeNode* l2) {
        vector<int> result;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                result.push_back(l1->val);
                l1 = l1->right;
            } else {
                result.push_back(l2->val);
                l2 = l2->right;
            }
        }
        while (l1 != nullptr) {
            result.push_back(l1->val);
            l1 = l1->right;
        }
        while (l2 != nullptr) {
            result.push_back(l2->val);
            l2 = l2->right;
        }
        return result;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        TreeNode* head1 = nullptr;
        TreeNode* head2 = nullptr;

        // Correctly passing the head reference
        convertToSortedDLL(root1, head1);
        convertToSortedDLL(root2, head2);

        // mergeToVector now uses the heads of the flattened lists
        return mergeToVector(head1, head2);
    }
};