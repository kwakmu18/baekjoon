#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(void) {
    fastio();

    int N, M;
    int A, B, C;
    cin >> N >> M;
    long long dist[N+1];
    for(int i=1;i<=N;i++) dist[i] = LONG_LONG_MAX;

    vector<tuple<int,int,int>> bus(M);

    for(int i=0;i<M;i++) {
        cin >> A >> B >> C;
        bus.push_back({A,B,C});
    }
    dist[1] = 0;
    for(int i=0;i<N;i++) {
        for(auto j=bus.begin();j!=bus.end();j++) {
            A = get<0>(*j); B = get<1>(*j); C = get<2>(*j);
            if (dist[A]==LONG_LONG_MAX) continue;
            if (dist[B] > dist[A] + C) {
                dist[B] = dist[A] + C;
                if (i==N-1) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    for(int i=2;i<=N;i++) {
        cout << (dist[i]==LONG_LONG_MAX ? -1:dist[i]) << "\n";
    }
}