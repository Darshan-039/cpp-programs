// Leetcode 3896. Minimum Operations to Make Array Alternating


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxVal = 0;

        // Step 1: Find maximum value in array
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        // Add extra buffer because next prime may be beyond max value
        int limit = maxVal + 100;

        // Step 2: Sieve of Eratosthenes to find prime numbers
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 3: Precompute next prime for every value
        vector<int> nextPrime(limit + 1);
        int nextP = -1;

        for (int i = limit; i >= 0; i--) {
            if (isPrime[i]) {
                nextP = i;
            }
            nextPrime[i] = nextP;
        }

        // Step 4: Precompute next non-prime for every value
        vector<int> nextNonPrime(limit + 1);
        int nextNP = -1;

        for (int i = limit; i >= 0; i--) {
            if (!isPrime[i]) {
                nextNP = i;
            }
            nextNonPrime[i] = nextNP;
        }

        long long operations = 0;

        // Step 5: Calculate minimum operations
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                // Even index should be prime
                operations += nextPrime[nums[i]] - nums[i];
            } else {
                // Odd index should be non-prime
                operations += nextNonPrime[nums[i]] - nums[i];
            }
        }

        return operations;
    }
};

int main() {
    int n;

    // Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    // Find and print minimum operations
    cout << "Minimum operations required: " << obj.minOperations(nums) << endl;

    return 0;
}