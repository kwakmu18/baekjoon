#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        int left=0, right=s.length()-1, call=1;
        bool isPalindrome=true;
        while (left<right) {
            if (s[left]!=s[right]) {
                isPalindrome=false; break;
            }
            call++;
            left++; right--;
        }
        cout << isPalindrome << " " << call << "\n";
    }
}