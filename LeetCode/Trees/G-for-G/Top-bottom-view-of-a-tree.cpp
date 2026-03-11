class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;

        map<int, int> topNode;
        queue<pair<Node* , int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int HD = temp.second;
            
            // remove these conditions to get bottom view
            // remove these conditions to get bottom view
            // remove these conditions to get bottom view
            // remove these conditions to get bottom view
            // remove these conditions to get bottom view
            // remove these conditions to get bottom view

            if(topNode.find(HD) == topNode.end()) {
                topNode[HD] = frontNode->data;
            }
            
            // Left child has HD of parent - 1
            if(frontNode->left) 
                q.push({frontNode->left, HD - 1});
                
            // Right child has HD of parent + 1
            if(frontNode->right) 
                q.push({frontNode->right, HD + 1});
        }
        
        // Since std::map is sorted by key (HD), iterating through it 
        // automatically gives us the nodes from leftmost HD to rightmost HD.
        for(auto i : topNode) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};