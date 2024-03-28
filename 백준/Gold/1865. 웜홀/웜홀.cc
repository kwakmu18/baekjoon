#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(void) {
    fastio();

    int TC;
    cin >> TC;
    while (TC--) {
        int N, M, W;
        int S, E, T;
        cin >> N >> M >> W;
        long long dist[N+1];
        for(int i=1;i<=N;i++) dist[i] = 1e9;
        dist[1] = 0;
        vector<tuple<int,int,int>> road(M), wormhall(N);

        for(int i=0;i<M;i++) {
            cin >> S >> E >> T;
            road.push_back({S,E,T}); road.push_back({E,S,T});
        }
        for(int i=0;i<W;i++) {
            cin >> S >> E >> T;
            wormhall.push_back({S,E,-T});
        }
        bool flag=true;
        for(int i=0;i<N;i++) {
            for(auto j=road.begin(); j!=road.end(); j++) {
                S = get<0>(*j); E = get<1>(*j); T = get<2>(*j);
                //if (dist[S]==LONG_LONG_MAX) continue;
                if (dist[E] > dist[S] + T) {
                    if (i==N-1) {
                        cout << "YES\n";
                        flag=false;
                        break;
                    }
                    dist[E] = dist[S] + T;
                }
            }
            if (!flag) break;
            for(auto j=wormhall.begin(); j!=wormhall.end(); j++) {
                S = get<0>(*j); E = get<1>(*j); T = get<2>(*j);
                //if (dist[S]==LONG_LONG_MAX) continue;
                if (dist[E] > dist[S] + T) {
                    if (i==N-1) {
                        cout << "YES\n";
                        flag=false;
                        break;
                    }
                    dist[E] = dist[S] + T;
                }
                //for(int k=1;k<=N;k++) cout << dist[k] << " ";
            }
            //cout << "\n";
        }
        if (flag) cout << "NO\n";
    }
}