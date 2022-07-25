#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vertex;
vector<int> vdepth;
int n, m, r;

void dfs(int now, int depth) {
    vdepth[now]=depth;
    int size=vertex[now].size();
    for(int i=0;i<size;i++) {
        if (vdepth[vertex[now][i]]!=-1) continue;
        dfs(vertex[now][i], depth+1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin >> n >> m >> r;
    vertex.resize(n+1);
    vdepth.resize(n+1);
    for(int i=1;i<=n;i++) vdepth[i]=-1;
    while (m--) {
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    for(int i=1;i<=n;i++) sort(vertex[i].begin(), vertex[i].end());
    dfs(r, 0);
    for(int i=1;i<=n;i++) cout << vdepth[i] << "\n";
}