// LeetCode 415. Add Strings


#include <iostream>
#include <string>
#include <algorithm> // for reverse

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1; // Pointer for end of num1
        int j = num2.size() - 1; // Pointer for end of num2
        int carry = 0;

        // Loop as long as there are digits to add or a carry remaining
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += (num1[i] - '0'); // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += (num2[j] - '0'); // Convert char to int
                j--;
            }

            ans.push_back((sum % 10) + '0'); // Get last digit and convert to char
            carry = sum / 10;                // Update carry
        }

        // The digits were added in reverse order, so we must reverse back
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string n1, n2;
    
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;
    
    cout << "Sum: " << sol.addStrings(n1, n2) << endl;
    
    return 0;
}