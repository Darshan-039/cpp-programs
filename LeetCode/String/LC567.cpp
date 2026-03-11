// Permutation in String

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool CheckEqual(int a[26], int b[26]) {
    for(int i = 0; i<26; i++) {
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

bool Permutation(string s1, string s2) {
    
    // s1 ni string ne arry bnavyo ch. vise
    int count1[26] = {0};
    for(int i = 0; i<s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }
     
    // s2 ni string ne array2 bnavyo of s1 size - windo
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};
    while(i < windowSize && i<s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    
    // Check is same | true 1
    if(CheckEqual (count1,count2)) return 1;
    
    // Check next Window 
    while(i<s2.length()) {
        int NewIndex = s2[i] - 'a';
        count2[NewIndex]++;
        
        int oldIndex = s2[i-windowSize] - 'a';
        count2[oldIndex]--;
        
        if(CheckEqual (count1,count2)) return 1;
         
        i++;
    }
    
    return 0;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    
    bool res = Permutation(s1, s2);
    cout << res;
}
