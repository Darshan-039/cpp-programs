// Leetcode 1404. Number of Steps to Reduce a Number in Binary Representation to One



// #include <iostream>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     int numSteps(string s) {

//         // Counts number of operations required
//         int steps = 0;

//         // Continue until binary number becomes "1"
//         while (s != "1") {

//             // CASE 1: Number is EVEN (last bit = 0)
//             // Divide by 2 → remove last bit
//             if (s.back() == '0') {
//                 s.pop_back();   // equivalent to right shift
//             }

//             // CASE 2: Number is ODD (last bit = 1)
//             // Add 1 to binary number
//             else {
//                 int i = s.length() - 1;

//                 // Handle carry while bits are '1'
//                 // Example: 111 + 1 → 000 with carry
//                 while (i >= 0 && s[i] == '1') {
//                     s[i] = '0';
//                     i--;
//                 }

//                 // If carry goes beyond MSB
//                 // Example: 111 → 1000
//                 if (i < 0)
//                     s = "1" + s;
//                 else
//                     s[i] = '1';   // place carry
//             }

//             // One operation completed
//             steps++;
//         }

//         return steps;
//     }
// };

// int main() {
//     string s;

//     cout << "Enter binary string: ";
//     cin >> s;

//     Solution obj;
//     int result = obj.numSteps(s);

//     cout << "Number of steps = " << result << endl;

//     return 0;
// }














// Approach - 2 (Optimized without modifying the string)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {

        int n = s.length();

        int carry = 0;      // represents carry generated while adding 1
        int operations = 0; // total steps required

        // Traverse from right to left (ignore MSB at index 0)
        for (int i = n - 1; i >= 1; i--) {

            // Current bit after including carry
            // (s[i] - '0') converts char → integer
            int bit = (s[i] - '0') + carry;

            // If bit becomes odd (1)
            // Need:
            //   1 step → add 1
            //   1 step → divide by 2
            if (bit % 2 == 1) {
                operations += 2;
                carry = 1;   // adding 1 creates carry
            }
            // If bit becomes even (0 or 2)
            // Only divide by 2
            else {
                operations += 1;
                // carry remains same
            }
        }

        // If carry still exists, one extra step needed
        return operations + carry;
    }
};

int main() {
    string s;

    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;
    int result = obj.numSteps(s);

    cout << "Number of steps = " << result << endl;

    return 0;
}