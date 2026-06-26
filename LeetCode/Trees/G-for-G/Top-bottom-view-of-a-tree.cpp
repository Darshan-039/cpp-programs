#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// Function to build tree using level order input
Node* buildTree() {
    int data;
    cout << "Enter root value (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;

        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftData;

        if (leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightData;

        if (rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }

    return root;
}

class Solution {
public:
    vector<int> topView(Node* root) {

        vector<int> ans;

        // Edge case: Empty tree
        if (!root) return ans;

        // Stores first node seen at every Horizontal Distance (HD)
        map<int, int> topNode;

        // Queue stores {Node, Horizontal Distance}
        queue<pair<Node*, int>> q;

        // Root has HD = 0
        q.push({root, 0});

        while (!q.empty()) {

            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int HD = temp.second;

            // Remove this Condition to get bottom view
            // Remove this Condition to get bottom view
            // Remove this Condition to get bottom view
            // Remove this Condition to get bottom view
            // Remove this Condition to get bottom view
            // Remove this Condition to get bottom view
            

            if (topNode.find(HD) == topNode.end()) 
                topNode[HD] = frontNode->data;
            

            // Left child -> HD - 1
            if (frontNode->left) 
                q.push({frontNode->left, HD - 1});
            

            // Right child -> HD + 1
            if (frontNode->right) 
                q.push({frontNode->right, HD + 1});
            
        }

        // Map is automatically sorted by HD
        // So nodes are retrieved from leftmost to rightmost
        for (auto node : topNode) {
            ans.push_back(node.second);
        }

        return ans;
    }
};

int main() {

    Node* root = buildTree();

    Solution obj;
    vector<int> result = obj.topView(root);

    cout << "\nTop View of Binary Tree: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}