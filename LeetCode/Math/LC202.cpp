// class Solution {
// public:
//     bool isHappy(int n) {
//         while(n != 1) {
//             if(n == 4) return false;

//             int ans = 0;
//             while(n > 0) {
//                 int digit = n % 10;
//                 ans = ans + (digit*digit);
//                 n = n / 10;
//             }
//             n = ans;
//         }

//         return true;
//     }
// };



// Optimal
// Floyd's cycle detection 
class Solution {
public:
    // Helper function to calculate the sum of squares of digits
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;     // extract last digit
            sum += digit * digit;   // square and add to sum
            n /= 10;                // remove last digit
        }
        return sum;
    }

    bool isHappy(int n) {
        // Floyd's Cycle Detection Algorithm
        int slow = n;              // will move one step at a time
        int fast = n;              // will move two steps at a time
        
        do {
            slow = getSum(slow);               // move 1 step
            fast = getSum(getSum(fast));       // move 2 steps
        } while (slow != fast);                // loop until a cycle is found
        
        // If both pointers meet at 1 => number is happy
        return slow == 1;
    }
};




// Hash Map
// class Solution {
// public:
//     int getSum(int n) {
//         int sum = 0;
//         while (n > 0) {
//             int digit = n % 10;
//             sum += digit * digit;
//             n /= 10;
//         }
//         return sum;
//     }

//     bool isHappy(int n) {
//         unordered_set<int> seen;
        
//         while (n != 1 && !seen.count(n)) {
//             seen.insert(n);
//             n = getSum(n);
//         }
        
//         return n == 1;
//     }
// };
