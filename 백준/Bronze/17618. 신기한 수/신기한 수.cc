#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, total;

int getDigitSum(int n) {
    int ret = 0;
    while (n>0) {
        ret += n%10;
        n/=10;
    }
    return ret;
}

int main(void) {
    fastio;
    cin >> N;
    for(int i=1;i<=N;i++) {
        if (i%getDigitSum(i)==0) total++;
    }
    cout << total;
}