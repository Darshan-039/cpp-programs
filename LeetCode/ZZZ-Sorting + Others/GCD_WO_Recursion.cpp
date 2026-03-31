// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int GCD(int a,int b) {
    if(a == 0) {
        return b;
    }
    
    if(b == 0) {
        return a;
    }
    
    while(a!=b) {
        if(a>b) {
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    return a;
}

int main() {
    cout << "Enter Two Number: " << endl;
    int a,b; 
    cin >> a >> b;
    
    int res = GCD(a,b);
    cout << res;
}