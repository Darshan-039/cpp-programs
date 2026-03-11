// Remove All Adjacent Duplicates In String

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string Permutation(string s) {
    string temp = "";
    
    for(char c : s) {
        if(!temp.empty() && temp.back() == c){
            temp.pop_back();
        }
        else{
            temp.push_back(c);
        }
    }
    return temp;
}

int main() {
    string s = "azxxzy";
    
    string ans = Permutation(s);
    cout << ans;
}
