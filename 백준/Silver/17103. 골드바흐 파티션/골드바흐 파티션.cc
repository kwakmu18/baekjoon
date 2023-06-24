#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<bool> prime(1000001, true);
    for(int i=2;i<=1000000;i++) {
        if (prime[i]) {
            for(int j=i*2;j<=1000000;j+=i) prime[j]=false;
        }
    }

    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        int cnt = 0;
        for(int i=2;i<=N/2;i++) {
            if (prime[i] && prime[N-i]) cnt++;
        }
        cout << cnt << "\n";
    }
}