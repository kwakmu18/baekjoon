#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    int aLen = a.length(), bLen = b.length();

    if (aLen!=bLen) return aLen<bLen;

    int aSum = 0, bSum = 0;

    for(int i=0;i<aLen;i++) {
        if (a[i]>='0' && a[i]<='9') aSum+=(a[i]-'0');
        if (b[i]>='0' && b[i]<='9') bSum+=(b[i]-'0');
    }
    if (aSum!=bSum) return aSum<bSum;
    else {
        for(int i=0;i<aLen;i++) {
            if (a[i]!=b[i]) return a[i]<b[i];
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<string> str(N);

    for(int i=0;i<N;i++) cin >> str[i];

    sort(str.begin(), str.end(), cmp);

    for(int i=0;i<N;i++) cout << str[i] << "\n";
}