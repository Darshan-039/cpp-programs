// String Compression

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void Permutation(vector<char> s) {
    int i = 0;
    int j = 0;
    int ansIndex = 0;
    int n = s.size();
    
    while(i<n){
        int count = 0;
        while(j<n && s[i] == s[j]) {
            j++;
            count++;
        }
        // aya kyare avshe 
        // New cha is come
        // nkr to vector pura traverse trdia
        
        s[ansIndex++] = s[i];
        
        if(count > 1) {
            string cnt = to_string(count);
            for(char ch: cnt) {
                s[ansIndex++] = ch;
            }
        }
        i=j;
        
    }
    
    cout << ansIndex << endl;
    for(char ch : s) {
        cout << ch;
    }
    
}

int main() {
    vector<char> s = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    Permutation(s);
    // cout << ans;
}
