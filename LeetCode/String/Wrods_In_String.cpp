#include <iostream>
#include <string>
using namespace std;

void countMax(string s) {
   int arr[26] = {0};
   int size = s.length();
   
    for(int i = 0; i<size; i++) {
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }
    
    int maxi = -1;
    int ans = 0;
    for(int i = 0; i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    
    char finalAns = ans + 'a';
    cout << finalAns << endl;
}

int main() {
    string s;
    cout << "Enter String:" << endl;
    cin >> s;

    countMax(s);
}
