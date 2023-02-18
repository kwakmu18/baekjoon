#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> depth;

int find_parent(int a, int b) {
    while (depth[a]!=depth[b]) {
        if (depth[a]>depth[b]) a=parent[a];
        else b=parent[b];
    }

    while (a!=b) {
        a=parent[a];
        b=parent[b];
    }

    return a;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    parent.resize(1024);
    depth.resize(1024);
    
    for(int i=1;i<=511;i++) {
        int d = (int)log2(i);
        int lChild = 2*i, rChild = 2*i+1;
        parent[lChild]=i;
        parent[rChild]=i;
        depth[lChild]=d+2;
        depth[rChild]=d+2;
        depth[i]=d+1;
    }

    int T, A, B;
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cout << 10*find_parent(A,B) << "\n";
    }
}