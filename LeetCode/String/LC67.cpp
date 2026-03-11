// Add Binary 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string AddBinary(string a, string b) {
    int i = a.length()-1;
    int j = b.length()-1;
    string result = "";
    int carry = 0;
    
    while(i>=0 || j>=0 || carry) {
        int sum = carry;
        if(i>=0) {
            sum+= a[i--] - '0';
        }
        if(j>=0) {
            sum+= b[j--] -'0';
        }
        
        result+= (sum%2) + '0';
        carry = sum/2;
    }
    
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    string a = "11";
    string b = "1";
    
    string ans = AddBinary(a,b);
    cout << ans;
}