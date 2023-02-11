#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> tree;
int *parent, *depth;
int *cost;

void dfs(int n, int d) {
    depth[n] = d;

    int size = tree[n].size();
    for(int i=0;i<size;i++) {
        int newNode = tree[n][i].first;
        int newCost = tree[n][i].second;
        if (parent[newNode]!=0) continue;
        cost[newNode]=newCost;
        parent[newNode] = n;
        dfs(newNode, d+1);
    }
}

long long int lca(int a, int b) {
    long long int c=0;
    while (depth[a]!=depth[b]) {
        if (depth[a]>depth[b]) {
            c+=cost[a];
            a=parent[a];
        }
        else {
            c+=cost[b];
            b=parent[b];
        }

    }

    while (a!=b) {
        c+=cost[a];
        a=parent[a];
        c+=cost[b];
        b=parent[b];
    }
    return c;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, A, B, C;
    cin >> N;

    tree.resize(N+1);
    parent = new int[N+1]{0};
    depth = new int[N+1]{0};
    cost = new int[N+1]{0};

    for(int i=0;i<N-1;i++) {
        cin >> A >> B >> C;
        tree[A].push_back({B,C});
        tree[B].push_back({A,C});
    }
    parent[1]=0;
    cost[1]=0;
    dfs(1,0);
    
    cin >> M;
    while (M--) {
        cin >> A >> B;
        cout << lca(A,B) << "\n";
    }
}