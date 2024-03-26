#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    return (a.first>b.first) || (a.second>b.second);
}

int ls[101];
int board[101];

int main(void) {
    int N, M;
    cin >> N >> M;
    for(int i=0;i<=100;i++) board[i] = INT_MAX;
    int u, v;
    for(int i=0;i<N;i++) {
        cin >> u >> v;
        ls[u] = v;
    }
    for(int i=0;i<M;i++) {
        cin >> u >> v;
        ls[u] = v;
    }

    priority_queue<pair<int,int>> pq;

    pq.push({0,1});

    int ans = INT_MAX;

    while (!pq.empty()) {
        int nowDice = pq.top().first;
        int nowPos = pq.top().second;
        pq.pop();
        if (nowPos==100) {
            ans = min(ans ,nowDice);
            continue;
        }
        if (board[nowPos]<=nowDice) continue;
        board[nowPos]=nowDice;
        for(int i=1;i<=6;i++) {
            if (nowPos+i>100) continue;
            if (ls[nowPos+i]!=0) {
                pq.push({nowDice+1, ls[nowPos+i]});
                continue;
            }
            pq.push({nowDice+1, nowPos+i});
        }
    }
    cout << ans;
}