#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> visited;
vector<vector<int>> v;
vector<int> order;
int r;
int cnt=-1;
void dfs(int n) {
    if (!visited[n]) {
        cnt++;
        visited[n]=true;
        order[n]=cnt;
        int size=v[n].size();
        if (size==1 && n!=(r-1)) {
            int back=n;
            while (cnt>0 && v[back].size()<=2) {
                cnt--;
                back=v[back][0];
            }
            return;
        }
        for(int i=0;i<size;i++) {
            if (!visited[v[n][i]]) {
                order[v[n][i]]=cnt;
                dfs(v[n][i]);
                
        }
        }
    }
    else return;
}
int main(void) {
    int n,m,a,b;
    cin >> n >> m >> r;
    v.resize(n);
    visited.resize(n);
    order.resize(n);
    for(int i=0;i<n;i++) {
        order[i]=-1;
        visited[i]=false;
    }
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++) sort(v[i].begin(), v[i].end());
    dfs(r-1);
    for(int i=0;i<n;i++) cout << order[i] << "\n";
}