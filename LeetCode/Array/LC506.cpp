class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int maxi = 0;
        for(int x : score) maxi = max(maxi, x);

        // temp[score] stores (original_index + 1)
        vector<int> temp(maxi + 1, 0);
        for(int i = 0; i < n; i++) {
            temp[score[i]] = i + 1;
        }

        vector<string> ans(n);
        int rank = 1;

        // Iterate backwards from the highest possible score
        for(int s = maxi; s >= 0; s--) {
            if(temp[s] > 0) { // If this score exists
                int originalIndex = temp[s] - 1;
                
                if(rank == 1) ans[originalIndex] = "Gold Medal";
                else if(rank == 2) ans[originalIndex] = "Silver Medal";
                else if(rank == 3) ans[originalIndex] = "Bronze Medal";
                else ans[originalIndex] = to_string(rank);
                
                rank++;
            }
        }
        return ans;
    }
};









class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        unordered_map<int, int> mp;

        // 1. Store original indices
        for(int i = 0; i < n; i++) mp[score[i]] = i;

        // 2. Sort in DESCENDING order (Highest score first)
        sort(score.begin(), score.end(), greater<int>());

        // 3. Assign Ranks
        for(int i = 0; i < n; i++) {
            if(i == 0) ans[mp[score[i]]] = "Gold Medal";
            else if(i == 1) ans[mp[score[i]]] = "Silver Medal";
            else if(i == 2) ans[mp[score[i]]] = "Bronze Medal";
            else ans[mp[score[i]]] = to_string(i + 1);
        }

        return ans;
    }
};