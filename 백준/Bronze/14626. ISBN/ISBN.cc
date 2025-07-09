#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    int result = 0, index=0;

    for(int i=0;i<s.length();i++) {
        char now = s[i];
        if (now == '*') {
            index = i;
            continue;
        }
        result += (now - '0') * (i%2==0?1:3);
    }
    for(int i=0;i<=9;i++) {
        if ((result + (index%2==0?i:i*3))%10==0) {
            cout << i << endl;
            break;
        }
    }
}