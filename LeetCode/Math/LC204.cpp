// Online C++ compiler to run C++ program online
// Count Primes
// Sieve of Eratosthenes.
#include <iostream>
#include <vector>
using namespace std;

void HowPrime(int n) {
    int count = 0;
    // int size = n+1;
    vector<bool> prime(n+1,true);
    
    prime[0] = prime[1] = false;
    
    for(int i = 2; i<n; i++) {
        if(prime[i]){
            count++;
            
            for(int j = 2*i; j<n; j=j+i) {
                prime[j] = 0;
            }
        }
    }
    
    cout << count << endl;
}

int main() {
    cout << "Enter Number: " << endl;
    int n; 
    cin >> n;
    
    HowPrime(n);
}