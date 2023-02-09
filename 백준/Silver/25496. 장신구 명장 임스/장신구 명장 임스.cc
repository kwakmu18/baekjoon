#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int P, N;
    cin >> P >> N;
    vector<int> acc(N);
    for(int i=0;i<N;i++) cin >> acc[i];
    sort(acc.begin(), acc.end());

    int newP = P, cnt=0;
    for(int i=0;i<N;i++) {
        if (newP<200) {
            cnt++;
            newP=newP+acc[i];
        }
        else break;
    }
    cout << cnt;
}