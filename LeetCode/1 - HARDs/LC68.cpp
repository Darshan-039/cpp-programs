// Leetcode Problem 68: Text Justification


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int MAX_WIDTH;

    // Helper function to construct a single line based on calculated space distribution
    string findLine(int i, int j, int eachGadhheSpace, int extraSpaceGadhha, vector<string>& words) {
        string line;

        for(int k = i; k < j; k++) {
            line += words[k];

            // If it's the last word of the line, don't add spaces after it
            if(k == j - 1) {
                continue;
            }

            // Add the base amount of spaces calculated for every "gadhha" (slot)
            for(int z = 1; z <= eachGadhheSpace; z++) {
                line += ' ';
            }

            // Distribute the remainder spaces one by one from left to right
            if(extraSpaceGadhha > 0) {
                line += ' ';
                extraSpaceGadhha--;
            }
        }

        // Handle trailing spaces: 
        // 1. For lines with only one word.
        // 2. For the last line of the text (which is left-justified).
        while(line.length() < MAX_WIDTH) {
            line += ' ';
        }

        return line;
    }


    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i = 0;

        while(i < n) {
            int letterCount = words[i].length(); // Total characters (letters only)
            int j = i + 1;
            int gadhhe = 0; // Number of slots between words

            // Greedily pack as many words as possible into the current line
            // Rule: Each word must be separated by at least one space
            while(j < n && words[j].length() + 1 + letterCount + gadhhe <= maxWidth) {
                letterCount += words[j].length();
                gadhhe += 1;
                j++;
            }

            // Calculate how much total space needs to be filled in the slots
            int remainingTotalSpace = maxWidth - letterCount;

            // eachGadhheSpace: Minimum spaces every slot gets
            // extraSpaceGadhha: Remainder spaces to be distributed to the leftmost slots
            int eachGadhheSpace = (gadhhe == 0) ? 0 : remainingTotalSpace / gadhhe;
            int extraSpaceGadhha = (gadhhe == 0) ? 0 : remainingTotalSpace % gadhhe;

            // Special Case: Last Line of the input
            // According to rules, the last line must be left-justified.
            // This means only 1 space between words, and all extra spaces go to the right.
            if(j == n) { 
                eachGadhheSpace = 1;
                extraSpaceGadhha = 0;
            }

            result.push_back(findLine(i, j, eachGadhheSpace, extraSpaceGadhha, words));

            // Move pointer i to the start of the next line
            i = j;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    
    vector<string> result = sol.fullJustify(words, maxWidth);
    
    for(const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}