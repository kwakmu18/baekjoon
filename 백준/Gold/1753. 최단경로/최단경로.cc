#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int V,E,K,u,v;
    short w;
    cin >> V >> E;
    cin >> K;
    vector<vector<pair<short,int>>> edge(V);
    for(int i=0;i<E;i++) {
        cin >> u >> v >> w;
        edge[u-1].push_back({w,v-1});
    }
    priority_queue<pair<int,int>> pq;
    vector<int> length(V);
    for(int i=0;i<V;i++) length[i]=INT_MAX;
    length[K-1]=0;
    pq.push({0,K-1});
    while (!pq.empty()) {
        int nowcost = -pq.top().first, nowvertex = pq.top().second;
        pq.pop();
        if (nowcost>length[nowvertex]) continue;
        int size=edge[nowvertex].size();
        for(int i=0;i<size;i++) {
            int newcost = nowcost+edge[nowvertex][i].first;
            if (length[edge[nowvertex][i].second]>newcost) {
                length[edge[nowvertex][i].second]=newcost;
                pq.push({-newcost,edge[nowvertex][i].second});
            }
        }
    }
    for(int i=0;i<V;i++) {
        if (length[i]==INT_MAX) cout << "INF\n";
        else cout << length[i] << "\n";
    }
}