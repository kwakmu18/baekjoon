#include <bits/stdc++.h>

using namespace std;

int N, M, iy, ix;
string line;
vector<vector<char>> campus;
vector<vector<bool>> visited;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int cnt = 0;

void dfs(int nowY, int nowX) {
    visited[nowY][nowX] = true;
    if (campus[nowY][nowX]=='P') cnt++;
    for(int i=0;i<4;i++) {
        int newY = nowY + dy[i], newX = nowX + dx[i];
        if (newY>=0 && newY < N && newX>=0 && newX<M && campus[newY][newX]!='X' && !visited[newY][newX]) dfs(newY,newX);
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    campus.resize(N);
    visited.resize(N);
    for(int i=0;i<N;i++) {
        campus[i].resize(M);
        visited[i].resize(M);
        cin >> line;
        for(int j=0;j<M;j++) {
            visited[i][j]=false;
            campus[i][j] = line[j];
            if (campus[i][j] == 'I') {
                iy = i;
                ix = j;
            }
        }
    }
    visited[iy][ix]=true;
    dfs(iy, ix);
    if (cnt!=0) cout << cnt;
    else cout << "TT";
}