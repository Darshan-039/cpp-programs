#include <iostream>
#include <string>
using namespace std;

void replaceSpacesInPlace(string &str) {
    int spaceCount = 0;
    int n = str.length();

    // Step 1: count spaces
    for (char ch : str) {
        if (ch == ' ')
            spaceCount++;
    }

    // Step 2: resize string to hold extra characters
    int newLength = n + spaceCount * 2;  // each space becomes 3 chars (@40)
    str.resize(newLength);

    // Step 3: work from end backwards
    int i = n - 1;
    int j = newLength - 1;

    while (i >= 0) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '4';
            str[j--] = '@';
            i--;
        } else {
            str[j--] = str[i--];
        }
    }
}

int main() {
    string s;
    cout << "Enter String: ";
    getline(cin, s);

    replaceSpacesInPlace(s);
    cout << s << endl;
}
