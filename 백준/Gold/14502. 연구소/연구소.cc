#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> curLab;
vector<vector<int>> originalLab;
vector<pair<int,int>> emptyPos;

int movPos[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(int y, int x) {
    curLab[y][x] = 2;
    for(int i=0;i<4;i++) {
        int newY = y+movPos[i][0], newX = x+movPos[i][1];
        if (newY>=0 && newY<N && newX>=0 && newX<M && curLab[newY][newX] == 0) dfs(newY, newX);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    originalLab.resize(N);
    for(int i=0;i<N;i++) {
        originalLab[i].resize(M);
        for(int j=0;j<M;j++) {
            cin >> originalLab[i][j];
            if (originalLab[i][j] == 0) emptyPos.push_back({i,j});
        }
    }

    int ans = 0;
    int emptyLen = emptyPos.size();

    for(int i=0;i<emptyLen-2;i++) {
        for(int j=i+1;j<emptyLen-1;j++) {
            for(int k=j+1;k<emptyLen;k++) {
                curLab = originalLab;
                curLab[emptyPos[i].first][emptyPos[i].second] = 1;
                curLab[emptyPos[j].first][emptyPos[j].second] = 1;
                curLab[emptyPos[k].first][emptyPos[k].second] = 1;

                for(int y=0;y<N;y++) {
                    for(int x=0;x<M;x++) {
                        if (originalLab[y][x]==2) dfs(y,x);
                    }
                }

                int emptyCnt = 0;
                for(int y=0;y<N;y++) {
                    for(int x=0;x<M;x++) {
                        if (curLab[y][x] == 0) emptyCnt++;
                    }
                }
                ans = max(ans, emptyCnt);
            }
        }
    }

    cout << ans << endl;
}