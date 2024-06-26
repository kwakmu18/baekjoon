#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(void) {
    fastio;

    int N;
    cin >> N;
    int arr[N], dp[N];
    int ans = 1;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if (arr[i]>arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                if (ans<dp[i]) ans=dp[i];
            }
        }
    }
    cout << ans;
}