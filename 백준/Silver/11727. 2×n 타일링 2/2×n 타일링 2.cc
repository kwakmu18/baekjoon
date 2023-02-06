#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int dp[1001];
    dp[0]=0;
    dp[1]=1;
    dp[2]=3;

    int n;
    cin >> n;
    for(int i=3;i<=n;i++) {
        dp[i]=(dp[i-1]%10007+(2*dp[i-2])%10007)%10007;
    }
    cout << dp[n];
    return 0;
}