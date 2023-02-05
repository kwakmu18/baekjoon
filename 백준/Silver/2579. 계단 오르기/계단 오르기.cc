#include <bits/stdc++.h>

using namespace std;




int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, newScore;
    cin >> N;
    vector<int> stairs(N+1);
    stairs[0]=0;
    for(int i=1;i<=N;i++) cin >> stairs[i];

    if (N<=2) {
        int sum=0;
        for(int i=0;i<=N;i++) sum+=stairs[i];
        cout << sum;
        return 0;
    }

    int notContinued[N+1]{0}, continued[N+1]{0};

    notContinued[1]=stairs[1];
    notContinued[2]=stairs[2]; continued[2]=stairs[1]+stairs[2];

    continued[3]=stairs[2]+stairs[3];
    notContinued[3]=stairs[1]+stairs[3];

    for(int i=4;i<=N;i++) {
        notContinued[i] = max(notContinued[i], max(notContinued[i-2]+stairs[i], continued[i-2]+stairs[i]));
        continued[i] = max(continued[i], max(notContinued[i-1]+stairs[i],notContinued[i-2]+stairs[i]));
    }
    cout << max(notContinued[N], continued[N]);
}