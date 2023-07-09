#include <bits/stdc++.h>

using namespace std;

int N, M, A, B, C, src, dst;
vector<vector<pair<int,int>>> bus;
vector<int> cost;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin >> M;
    bus.resize(N);
    cost.resize(N);
    for(int i=0;i<N;i++) cost[i] = INT_MAX;
    for(int i=0;i<M;i++) {
        cin >> A >> B >> C;
        bus[A-1].push_back({C, B-1});
    }
    for(int i=0;i<N;i++) {
        sort(bus[i].begin(), bus[i].end());
    }

    cin >> src >> dst;
    priority_queue<pair<int,int>> pq;
    pq.push({0,src-1});
    while (!pq.empty()) {
        pair<int,int> now = pq.top(); pq.pop();
        int nowCost = now.first, nowCity = now.second;
        int size = bus[nowCity].size();
        for(int i=0;i<size;i++) {
            int newCity = bus[nowCity][i].second, newCost = nowCost + bus[nowCity][i].first;
            if (newCost<cost[newCity]) {
                pq.push({newCost, newCity});
                cost[newCity] = newCost;
            }
        }
    }
    cout << cost[dst-1];
}