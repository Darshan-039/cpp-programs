class Solution {
public:

    /*
        We avoid building the full string.

        Each operation doubles the string:
        length = 1 → 2 → 4 → 8 → ...

        If k lies in:
        - First half → same as previous
        - Second half → map to first half and adjust
    */
    char kthCharacter(long long k, vector<int>& operations) {

        // Base case: first character is always 'a'
        if(k == 1)
            return 'a';

        long long length = 1;          // initial length
        long long newK = -1;
        int operationType = -1;

        // Find which operation level contains kth position
        for(int i = 0; i < operations.size(); i++) {

            length *= 2;               // string doubles each time

            if(length >= k) {
                operationType = operations[i];
                newK = k - length / 2; // map to previous half
                break;
            }
        }

        // Recursive call to find original character
        char ch = kthCharacter(newK, operations);

        // If operation was 0 → just copy
        if(operationType == 0)
            return ch;

        // If operation was 1 → shift character by 1 (circular)
        else
            return (ch == 'z') ? 'a' : ch + 1;
    }
};