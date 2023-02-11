#include <bits/stdc++.h>
#define LOG 21

using namespace std;

vector<vector<int>> tree;
int N;
int *depth;
int **parent;

void dfs(int n, int d) {
    depth[n] = d;

    int size = tree[n].size();
    for(int i=0;i<size;i++) {
        int newNode = tree[n][i];
        if (depth[newNode]!=0) continue;
        parent[newNode][0] = n;
        dfs(newNode, d+1);
    }
}

void set_parent() {
    dfs(1,0);
    parent[1][0]=1;
    depth[1]=0;
    for(int i=1;i<LOG;i++) {
        for(int j=1;j<=N;j++) parent[j][i] = parent[parent[j][i-1]][i-1];
    }
}

int lca(int a, int b) {
    if (depth[a]>depth[b]) swap(a,b);
    
    for(int i=LOG-1;i>=0;i--) {
        if (depth[b]-depth[a]>=(1<<i)) b=parent[b][i];
    }

    if (a==b) return a;

    for(int i=LOG-1;i>=0;i--) {
        if (parent[a][i]!=parent[b][i]) {
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M, A, B;
    cin >> N;
    tree.resize(N+1);
    depth = new int[N+1]{0};
    parent = new int *[N+1]{0};
    for(int i=0;i<=N;i++) {
        parent[i] = new int[LOG];
        for(int j=0;j<LOG;j++) parent[i][j]=0;
    }

    for(int i=0;i<N-1;i++) {
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    set_parent();

    cin >> M;

    while (M--) {
        cin >> A >> B;
        cout << lca(A,B) << "\n";
    }
}