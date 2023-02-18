#include <bits/stdc++.h>

using namespace std;

int n,a,b,c;
int maxCostNode, maxCost;
vector<int> visited;
vector<vector<pair<int,int>>> tree;
vector<int> cost;

void dfs1(int now, int c) {
    visited[now]=true;
    int size = tree[now].size();
    for(int i=0;i<size;i++) {
        int nowNode = tree[now][i].first, nowCost = c+tree[now][i].second;
        if (visited[nowNode]) continue;
        cost[nowNode]=nowCost;
        if (nowCost>cost[maxCostNode]) maxCostNode=nowNode;
        dfs1(nowNode,nowCost);
    }
}

void dfs2(int now, int c) {
    visited[now]=true;
    int size=tree[now].size();
    for(int i=0;i<size;i++) {
        int nowNode = tree[now][i].first, nowCost = c+tree[now][i].second;
        if (visited[nowNode]) continue;
        if (nowCost>maxCost) maxCost=nowCost;
        dfs2(nowNode,nowCost);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    if (n==1) {
        cout << 0;
        return 0;
    }
    tree.resize(n+1);
    cost.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<=n;i++) {
        cost[i]=0;
        visited[i]=false;
    }

    for(int i=1;i<=n;i++) {
        cin >> a;
        cin >> b;
        while (b!=-1) {
            cin >> c;
            tree[a].push_back({b,c});
            cin >> b;
        }
    }

    dfs1(1,0);
    for(int i=1;i<=n;i++) visited[i]=false;

    dfs2(maxCostNode, 0);
    cout << maxCost;
}