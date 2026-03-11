// SQRt using Binary Search

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Base cases
        
        int s = 0;
        int e = x;
        int ans = -1;
        
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long square = mid * mid;

            if (square == x) {
                return mid;  // perfect square
            }
            if (square < x) {
                ans = mid;   // store possible answer
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }
        return ans;  // floor of sqrt(x)
    }
};
