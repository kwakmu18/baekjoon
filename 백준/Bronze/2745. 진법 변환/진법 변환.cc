#include <bits/stdc++.h>

using namespace std;

int change(char digits) {
   if (digits>='0' && digits<='9') return digits-'0';
   else return digits-'A'+10;
}

int main(void) {
   string number;
   int radix;
   cin >> number >> radix;

   int length = number.length();
   int base = 1, result = 0;
   for(int i=length-1;i>=0;i--) {
      result += change(number[i]) * base;
      base *= radix;
   }
   cout << result;
}