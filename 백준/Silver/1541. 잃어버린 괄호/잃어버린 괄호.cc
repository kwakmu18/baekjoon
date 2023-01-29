#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int sIndex = 0, sLength = s.length(), ans=0, now=0, now2=0;
    while (sIndex<sLength) {
        if (s[sIndex]=='-') {
            sIndex++;
            while (sIndex<sLength && s[sIndex]!='-') {
                if (s[sIndex]>='0' && s[sIndex]<='9') {
                    now2=now2*10+(s[sIndex]-'0');
                }
                else if (s[sIndex]=='+') {
                    now+=now2;
                    now2=0;
                }
                sIndex++;
            }
            if (s[sIndex]=='-' || sIndex==sLength) now+=now2;
            ans-=now;
        }
        else {
            while (sIndex<sLength && s[sIndex]!='-') {
                if (s[sIndex]>='0' && s[sIndex]<='9') {
                    now2=now2*10+(s[sIndex]-'0');
                }
                else if (s[sIndex]=='+') {
                    now+=now2;
                    now2=0;
                }
                sIndex++;
            }
            if (s[sIndex]=='-' || sIndex==sLength) now+=now2;
            ans+=now;
        }
        now=0;
        now2=0;
    }
    cout << ans;
}