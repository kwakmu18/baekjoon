#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(void) {
    fastio;

    int N;
    cin >> N;
    int arr[N+1]={0,}, dp[N+1]={-INT_MAX,};
    int idx = 1;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
        int result = lower_bound(dp, dp+idx, arr[i])-dp;
        if (result==idx) {
            dp[idx++] = arr[i];
        }
        else {
            dp[result] = min(dp[result], arr[i]);
        }
    }
    cout << idx-1;
}