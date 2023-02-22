#include <bits/stdc++.h>

using namespace std;

map<string, double> credit;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str[5];
    int strLength[5], maxLength=0;

    for(int i=0;i<5;i++) {
        cin >> str[i];
        strLength[i] = str[i].length();
        if (maxLength<strLength[i]) maxLength=strLength[i];
    }

    for(int i=0;i<maxLength;i++) {
        for(int j=0;j<5;j++) {
            if (strLength[j]<=i) continue;
            cout << str[j][i];
        }
    }
}