#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(void) {
    fastio();

    int N;
    cin >> N;
    int cost[N][3];
    int dp[N][3];

    for(int i=0;i<N;i++) {
        for(int j=0;j<3;j++) {
            cin >> cost[i][j];
            dp[i][j] = INT_MAX;
        }
        if (i==0) {
            dp[0][0] = cost[0][0];
            dp[0][1] = cost[0][1];
            dp[0][2] = cost[0][2];
        }
        else {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    if (j==k) continue;
                    dp[i][j] = min(dp[i][j], cost[i][j] + dp[i-1][k]);
                }
            }
        }
    }
    cout << min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
}