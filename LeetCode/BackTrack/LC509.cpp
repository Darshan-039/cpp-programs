// Leetcode 509. Fibonacci Number




// Approach - 1 : Using Recursion

// #include <iostream>
// #include <vector>
// using namespace std;

// int fibonacci(int n) {
//     if(n<=1) {
//         return n;
//     }
//     int ans = 0;
//     int pos1 = 0;
//     int pos2 = 1;
    
//     for(int i = 2; i<n; i++) {
//         ans = pos1+pos2;
//         pos1 = pos2;
//         pos2 = ans;
//     }
    
//     return ans;
// }

// int main() {
//     cout << "Enter Number: " << endl;
//     int n;
//     cin >> n;
//     int ans = fibonacci(n);
//     cout << ans << endl;
// }

















// Approach - 2 : Using For Loop

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    // 0 1 1 2 3 5 8 13 21
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    int ans = fibonacci(n-1) + fibonacci(n-2);
    
    return ans;
}

int main() {
    cout << "Enter Number: " << endl;
    int n;
    cin >> n;
    int ans = fibonacci(n);
    cout << ans << endl;
}