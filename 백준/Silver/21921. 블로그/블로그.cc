#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int X, N, input;
    cin >> N >> X;
    int *days = new int[N+1];
    days[0]=0;
    for(int i=1;i<=N;i++) {
        cin >> input;
        days[i]=days[i-1]+input;
    }
    int max=0, cnt=0;
    for(int i=X;i<=N;i++) {
        int newMax = days[i]-days[i-X];
        if (newMax>max) {
            max=newMax;
            cnt=1;
        }
        else if (newMax==max) cnt++;
    }
    if (max==0) cout << "SAD";
    else cout << max << "\n" << cnt;
}