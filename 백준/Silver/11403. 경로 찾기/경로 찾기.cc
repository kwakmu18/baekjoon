#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
void dfs(int first, int now) {
    if (visited[now]) return;
    if (first!=now) visited[now]=true;
    int size = graph[now].size();
    for(int i=0;i<size;i++) {
        if (graph[now][i]==first) visited[first]=true;
        if (!visited[graph[now][i]]) {
            dfs(first, graph[now][i]);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    graph.resize(N);
    visited.resize(N);
    bool isConnected;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> isConnected;
            if (isConnected) graph[i].push_back(j);
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) visited[j]=false;
        dfs(i,i);
        for(int j=0;j<N;j++) cout << visited[j] << " ";
        cout << "\n";
    }
}