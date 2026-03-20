// Leetcode 1312. Minimum Insertion Steps to Make a String Palindrome



#include <bits/stdc++.h>
using namespace std;

class Fancy {
public:
    typedef long long ll;

    ll M = 1e9 + 7;

    // Stores normalized values
    vector<ll> seq;

    // Global transformations
    ll add = 0;   // total addition
    ll mult = 1;  // total multiplication

    // 🔹 Fast exponentiation (modular power)
    long long power(long long a, long long b) {
        if(b == 0) return 1;

        long long half = power(a, b / 2);
        long long result = (half * half) % M;

        if(b % 2 == 1) result = (result * a) % M;

        return result;
    }

    Fancy() { }

    // 🔹 Append value after reversing transformations
    void append(int val) {
        // Reverse formula:
        // actual = stored * mult + add
        // ⇒ stored = (val - add) / mult

        long long x = ((val - add) % M + M) % M;

        // Multiply with modular inverse of mult
        x = (x * power(mult, M - 2)) % M;

        seq.push_back(x);
    }

    // 🔹 Add 'inc' to all elements
    void addAll(int inc) {
        add = (add + inc) % M;
    }

    // 🔹 Multiply all elements by m
    void multAll(int m) {
        add = (add * m) % M;
        mult = (mult * m) % M;
    }

    // 🔹 Get value at index after applying transformations
    int getIndex(int idx) {
        if(idx >= seq.size()) return -1;

        return (seq[idx] * mult + add) % M;
    }
};

int main() {
    Fancy obj;

    // 🔹 Sample operations

    obj.append(2);        // [2]
    obj.addAll(3);        // [5]
    obj.append(7);        // [5,7]
    obj.multAll(2);       // [10,14]
    
    cout << obj.getIndex(0) << endl; // 10
    cout << obj.getIndex(1) << endl; // 14

    obj.addAll(3);        // [13,17]
    obj.append(10);       // [13,17,10]

    cout << obj.getIndex(2) << endl; // 10

    return 0;
}