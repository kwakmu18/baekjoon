#include <bits/stdc++.h>

using namespace std;

int T, N;

int get_dist(string a, string b, string c) {
    int total = 0;
    for(int i=0;i<4;i++) {
        if (a[i]!=b[i]) total+=1;
        if (b[i]!=c[i]) total+=1;
        if (c[i]!=a[i]) total+=1;
    }
    return total;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<string> mbti(N);
        for(int i=0;i<N;i++) cin >> mbti[i];
        if (N>32) {
            cout << "0\n";
            continue;
        }
        int ans = INT_MAX;
        for(int i=0;i<N-2;i++) {
            for(int j=i+1;j<N-1;j++) {
                for(int k=j+1;k<N;k++) {
                    int now = get_dist(mbti[i], mbti[j], mbti[k]);
                    if (now<ans) ans=now;
                }
            }
        }
        cout << ans << "\n";
    }
}