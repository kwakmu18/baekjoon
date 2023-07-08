#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> m;
vector<vector<int>> dist;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    m.resize(N); dist.resize(N);
    queue<pair<int, pair<int,int>>> q;
    for(int i=0;i<N;i++) {
        m[i].resize(M);
        dist[i].resize(M);
        for(int j=0;j<M;j++) {
            cin >> m[i][j];
            if (m[i][j]==2) {
                q.push({0,{i,j}});
                dist[i][j] = 0;
            }
            else if (m[i][j]==1) dist[i][j] = INT_MAX;
            else dist[i][j] = 0;
        }
    }

    while (!q.empty()) {
        pair<int,pair<int,int>> now = q.front(); q.pop();
        int nowY = now.second.first, nowX = now.second.second, nowCost = now.first;
        if (nowCost>dist[nowY][nowX]) continue;

        for(int i=0;i<4;i++) {
            int newY = nowY + dy[i], newX = nowX + dx[i], newCost = nowCost+1;
            if (newY>=0 && newY<N && newX>=0 && newX<M) {
                if (dist[newY][newX]>newCost) {
                    dist[newY][newX] = newCost;
                    q.push({newCost, {newY,newX}});
                }
            }
        }

    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if (dist[i][j] == INT_MAX) cout << "-1 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

}