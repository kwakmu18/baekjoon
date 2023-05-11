#include <bits/stdc++.h>

using namespace std;

int change(char digits) {
   if (digits>='0' && digits<='9') return digits-'0';
   else return digits-'A'+10;
}

int main(void) {
   int number, radix;
   cin >> number >> radix;

   vector<int> digits;

   while (number!=0) {
      digits.push_back(number%radix);
      number/=radix;
   }
   for(int i=digits.size()-1;i>=0;i--) {
      if (digits[i]<=9) cout << digits[i];
      else cout << (char)(digits[i]-10+'A');
   }
}