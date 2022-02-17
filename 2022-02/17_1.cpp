#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;
int cnt=1;

void dfs(int r, int n, int *order) {
    int size=v[r].size();
    order[r]=cnt;

    visited[r]=true;
    for(int i=0;i<size;i++) {
        if (!visited[v[r][i]]) {
            visited[v[r][i]]=true;
            dfs(v[r][i], n, order);
            cnt++;
        }
    }
    return;
}

int main(void) {
    int n, m, r, a, b;
    cin >> n >> m >> r;
    int *order=new int[n+1]{0};
    v.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(), v[i].end());
    dfs(r, n, order);
    for(int i=1;i<=n;i++) cout << order[i] << "\n";
}
