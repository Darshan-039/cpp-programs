// Leetcode 394. Decode String



#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;     // stores repetition counts
        stack<string> stringStack; // stores previous strings

        string curr = "";  // current working string
        int num = 0;       // current number (for multi-digit)

        for (char ch : s) {

            // If digit, build the number (handles multi-digit like 12[a])
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // When '[' encountered → push current state to stacks
            else if (ch == '[') {
                countStack.push(num);   // push repetition count
                stringStack.push(curr); // push current string

                // reset for new substring
                num = 0;
                curr = "";
            }

            // When ']' encountered → decode current part
            else if (ch == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string temp = stringStack.top();
                stringStack.pop();

                // repeat current substring 'repeat' times
                for (int i = 0; i < repeat; i++) {
                    temp += curr;
                }

                curr = temp; // update current string
            }

            // Normal character → just append
            else {
                curr += ch;
            }
        }

        return curr;
    }
};

int main() {
    string s;
    cout << "Enter encoded string: ";
    cin >> s;

    Solution obj;
    string result = obj.decodeString(s);

    cout << "Decoded string: " << result << endl;

    return 0;
}