#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
int *depth;
int *parent;

void dfs(int n, int d) {
    depth[n] = d;

    int size = tree[n].size();
    for(int i=0;i<size;i++) {
        int newNode = tree[n][i];
        if (depth[newNode]!=0) continue;
        parent[newNode] = n;
        dfs(newNode, d+1);
    }
}

int lca(int a, int b) {
    while (depth[a]!=depth[b]) {
        if (depth[a]>depth[b]) a = parent[a];
        else b = parent[b];
    }

    while (a!=b) {
        a = parent[a];
        b = parent[b];
    }
    
    return a;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, A, B;
    cin >> N;

    tree.resize(N+1);
    parent = new int[N+1]{0};
    depth = new int[N+1]{0};

    for(int i=0;i<N-1;i++) {
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    dfs(1,0);
    parent[1]=1;
    depth[1]=0;

    cin >> M;

    while (M--) {
        cin >> A >> B;
        cout << lca(A,B) << "\n";
    }
}