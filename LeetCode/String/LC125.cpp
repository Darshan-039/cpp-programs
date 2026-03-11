// Valid Palindrome

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool valid(char ch) {
        return ( (ch >= 'a' && ch <= 'z') ||
                 (ch >= 'A' && ch <= 'Z') ||
                 (ch >= '0' && ch <= '9') );
    }

    char toLowerCase(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        return ch - 'A' + 'a';
    }

    bool checkPalindrome(string a) {
        int s = 0, e = a.length() - 1;
        while (s <= e) {
            if (a[s] != a[e]) return false;
            s++; e--;
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";
        for (char c : s)
            if (valid(c)) temp.push_back(toLowerCase(c));

            
        return checkPalindrome(temp);
    }
};

int main() {
    Solution obj;
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    if (obj.isPalindrome(str))
        cout << "True\n";
    else
        cout << "False\n";
}
