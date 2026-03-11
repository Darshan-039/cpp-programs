// Check a number is palindrome or not
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool checkPalindrome(int x) {
   if(x<0 || x>=2147483647){
       return false;
   }
   
   long int num = 0;
   int y = x;
   while(x>0) {
       num = num*10;
       if(num > 2147483647) {
           return false;
       }
       num = num + (x%10);
       x = x/10;
   }
   
   if(num == y) {
       return true;
   }
   else{
       return false;
   }
}

int main() {
    int num = 121;
    int res = checkPalindrome(num);
    cout << res;
}