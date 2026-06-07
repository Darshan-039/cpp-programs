// Leetcode 69. Sqrt(x)


#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int s = 0;
        int e = x;
        int ans = -1;

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long square = mid * mid;

            if (square == x) {
                return mid;
            }

            if (square < x) {
                ans = mid;
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    int x;

    cout << "Enter number: ";
    cin >> x;

    Solution obj;

    cout << "Square root is: " << obj.mySqrt(x);

    return 0;
}