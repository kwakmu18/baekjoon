#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    string S, subS;
    cin >> S;
    int SLen = S.length();

    unordered_set<string> us;
    for(int i=0;i<SLen;i++) {
        subS = "";
        for(int j=i;j<SLen;j++) {
            subS+=S[j];
            us.insert(subS);
        }
    }

    cout << us.size();
    return 0;
}