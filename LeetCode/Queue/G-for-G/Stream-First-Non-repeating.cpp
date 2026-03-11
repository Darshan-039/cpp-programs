#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string firstNonRepeating(string &s) {
        unordered_map<char, int> count;
        queue<char> q;
        string ans = "";
        
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // 1. Update the frequency count
            count[ch]++;
            
            // 2. Push current character into queue
            q.push(ch);
            
            // 3. Remove characters from front if they are repeating
            while(!q.empty()) {
                if(count[q.front()] > 1) {
                    q.pop();
                } else {
                    // Non-repeating character found at front
                    ans.push_back(q.front());
                    break;
                }
            }
            
            // 4. If queue becomes empty, no non-repeating char exists for this stream
            if(q.empty()) {
                ans.push_back('#');
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // --- INPUT SECTION ---
    string s = "aabc"; 
    // Explanation: 
    // Stream "a" -> "a"
    // Stream "aa" -> "#" (a repeats)
    // Stream "aab" -> "b" (a repeats, b is first non-repeating)
    // Stream "aabc" -> "b" (b is still first non-repeating)
    
    cout << "Input Stream: " << s << endl;

    // --- EXECUTION ---
    string result = sol.firstNonRepeating(s);

    // --- OUTPUT SECTION ---
    cout << "Resulting Stream: " << result << endl; // Output: a#bb

    return 0;
}