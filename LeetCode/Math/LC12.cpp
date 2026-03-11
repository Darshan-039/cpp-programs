// Leetcode - 12: Integer to Roman


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Approach - 1
class Solution {
public:
    string intToRoman(int num) {
        // static ensures these are only initialized once for all function calls
        static const vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const vector<string> sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ans = "";

        for(int i = 0; i < 13; i++) {
            if(num == 0) break;

            int times = num / val[i];
            
            // Append the symbol 'times' number of times
            while(times--) {
                ans += sym[i];
            }

            num %= val[i]; // Get the remainder for the next iteration
        }

        return ans;
    }
};






// Approach - 2
// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<int> val = {
//             1000, 900, 500, 400,
//             100, 90, 50, 40,
//             10, 9, 5, 4, 1
//         };

//         vector<string> sym = {
//             "M", "CM", "D", "CD",
//             "C", "XC", "L", "XL",
//             "X", "IX", "V", "IV", "I"
//         };

//         string ans = "";
//         for (int i = 0; i < val.size(); i++) {
//             while (num >= val[i]) {
//                 num -= val[i];
//                 ans += sym[i];
//             }
//         }
//         return ans;
//     }
// };




int main() {
    Solution sol;
    int inputNum;

    cout << "Enter an integer to convert to Roman (1-3999): ";
    if (!(cin >> inputNum)) {
        cout << "Invalid input. Please enter a number." << endl;
        return 1;
    }

    if (inputNum < 1 || inputNum > 3999) {
        cout << "Out of range for standard Roman Numerals (1-3999)." << endl;
    } else {
        string result = sol.intToRoman(inputNum);
        cout << "Roman Numeral: " << result << endl;
    }

    return 0;
}