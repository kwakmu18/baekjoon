#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, input;
    long long P[101];
    P[1]=1; P[2]=1; P[3]=1;
    for(int i=4;i<=100;i++) {
        P[i]=P[i-3]+P[i-2];
    }
    cin >> T;
    while (T--) {
        cin >> input;
        cout << P[input] << "\n";
    }
}