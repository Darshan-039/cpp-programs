// Leetcode 151: Reverse Words in a String

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        int n = s.size();
        string temp = "";
        
        for(int i = 0; i < n; ) {
            if(s[i] != ' ') {
                while(i < n && s[i] != ' ')
                    temp.push_back(s[i++]);
                temp.push_back(' ');
            }
            else i++;
        }

        if(!temp.empty()) temp.pop_back();  // remove last space
        s = temp;

        // Step 2: Reverse whole string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word in the string
        int i = 0;
        for(int j = 0; j <= s.size(); j++) {
            if(j == s.size() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        
        return s;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); // input with spaces

    Solution obj;
    cout << "Reversed Words: " << obj.reverseWords(s) << endl;

    return 0;
}





/* 

<?php 
$servername = "localhost";
$username = "username";
$password = "password";

// Create connection ..
$con = new mysqli($servername, $username, $password);

// Check connection .. 
if(connection -> error) {
die("Connection Failed:" .$connection -> error);

// Create Database ...
$sql = "CREATE DATABASE myDB";

if($conn -> query($sql) == TRUE) {
echo "Database created successfully";}

}






*/