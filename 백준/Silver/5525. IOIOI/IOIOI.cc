#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, ans=0;
    cin >> N;
    string P = "I", S;
    for(int i=0;i<N;i++) P+="OI";
    cin >> M;
    cin >> S;
    for(int i=0;i<M-N;i++) {
        if (S.substr(i,2*N+1).compare(P)==0) ans++;
    }
    cout << ans;
}