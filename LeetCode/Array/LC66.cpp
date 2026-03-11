// Pluse One in given array
#include <iostream>
#include <vector>
using namespace std;

vector<int> sum(vector<int>& digits) {
    int n = digits.size();

        // Traverse from last digit to first
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;     // Simple case: just add 1 and return
                return digits;
            }
            digits[i] = 0;       // If digit is 9, set to 0 and continue
        }

        // If all digits were 9, e.g. 999 -> 1000
        digits.insert(digits.begin(), 1);
        return digits;
}

int main() {
    vector<int> digits = {1,2,3};
    vector<int> ans = sum(digits);
    
    for(int i: ans) {
        cout << i;
    }
}