#include <bits/stdc++.h>
#define NUM 1000000009

using namespace std;

long long dp[1000001]{0};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dp[0]=0; dp[1]=1; dp[2]=2; dp[3]=4;
    for(int i=4;i<=1000000;i++) {
        dp[i]=(dp[i-3]%NUM+dp[i-2]%NUM+dp[i-1]%NUM)%NUM;
    }

    int T, input;
    cin >> T;
    while (T--) {
        cin >> input;
        cout << dp[input] << "\n";
    }
}