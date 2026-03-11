// Remove all Occurrences of a subString

#include <iostream>
#include <string>
using namespace std;

void removePart(string s, string part) {
    while(s.find(part) < s.size()) {
        s.erase(s.find(part), part.size());
    }
    
    cout << s << endl;
}

int main() {
    string s = "daabcbaabcbc";
    string r = "abc";
    
    removePart(s,r);
}
