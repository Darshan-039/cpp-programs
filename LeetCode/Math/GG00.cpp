// GeeksforGeeks: Factorial of a Large Number




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to multiply current number with multiplier
    // nums stores digits in reverse order
    void solve(vector<int> &nums, int &size, int multiplier) {

        int carry = 0;

        // Multiply each digit with multiplier
        for(int i = 0; i < size; i++) {

            int result = (multiplier * nums[i]) + carry;

            // Store last digit
            nums[i] = result % 10;

            // Update carry
            carry = result / 10;
        }

        // If carry remains, add new digits
        while(carry > 0) {
            nums[size] = carry % 10;
            size++;
            carry /= 10;
        }
    }

    vector<int> factorial(int n) {

        // Vector to store digits of factorial
        vector<int> nums(10000, 0);

        nums[0] = 1; // 0! or starting value

        int size = 1; // current number of digits

        // Multiply numbers from 2 to n
        for(int multiplier = 2; multiplier <= n; multiplier++) {
            solve(nums, size, multiplier);
        }

        // Store result in correct order
        vector<int> ans;
        for(int i = size - 1; i >= 0; i--) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    int n;
    cout << "Enter number: ";
    cin >> n;

    vector<int> result = obj.factorial(n);

    cout << "Factorial = ";
    for(int digit : result) {
        cout << digit;
    }

    cout << endl;

    return 0;
}