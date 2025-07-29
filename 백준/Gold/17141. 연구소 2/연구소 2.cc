#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> curLab;
// curLab
// 0: 빈칸
// 1: 벽
// 2: 바이러스 후보군
// 3: 바이러스 놓은 곳

vector<vector<int>> cost;
// cost
// -1: 도달할 수 없는 곳
// 이외: 소요 시간
vector<pair<int,int>> virusPos;
vector<vector<vector<int>>> virusResult;
vector<int> selectedVirus;
vector<bool> usedVirus;

int movPos[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void DFS(int index, int curY, int curX, int curCost) {
    if (virusResult[index][curY][curX]==-1) virusResult[index][curY][curX] = curCost;
    else virusResult[index][curY][curX] = min(virusResult[index][curY][curX], curCost);

    for(int i=0;i<4;i++) {
        int newY = curY+movPos[i][0], newX = curX+movPos[i][1];
        if (newY>=0 && newY<N && newX>=0 && newX<N && curLab[newY][newX]!=1) {
            if (virusResult[index][newY][newX]==-1) DFS(index, newY, newX, curCost+1);
            else if (virusResult[index][newY][newX]>curCost+1) DFS(index, newY, newX, curCost+1);
        }
    }
}

int ans = -1;

void SelectVirus(int curCnt, int curIndex) {
    if (curCnt == M) {
        for(int y=0;y<N;y++) {
            for(int x=0;x<N;x++) cost[y][x] = virusResult[selectedVirus[0]][y][x];
        }

        for(int i=1;i<M;i++) {
            for(int y=0;y<N;y++) {
                for(int x=0;x<N;x++) {
                    if (curLab[y][x]==1) continue;
                    //else if (virusResult[selectedVirus[i]][y][x] == -1) return;
                    else if (cost[y][x] == -1) cost[y][x] = virusResult[selectedVirus[i]][y][x];
                    else if (cost[y][x] != -1 && virusResult[selectedVirus[i]][y][x]!=-1)
                        cost[y][x] = min(cost[y][x], virusResult[selectedVirus[i]][y][x]);
                }
            }
        }

        int curAns = 0;
        for(int y=0;y<N;y++) {
            for(int x=0;x<N;x++) {
                if (curLab[y][x] == 1) continue;
                else if (cost[y][x] == -1) return;
                else curAns = max(curAns, cost[y][x]);
            }
        }
        if (ans == -1) ans = curAns;
        else ans = min(ans, curAns);
        return;
    }

    int virusSize = virusPos.size();
    for(int i=curIndex;i<virusSize;i++) {
        if (usedVirus[i]) continue;
        if (curCnt>=1 && selectedVirus[curCnt-1]>i) continue;
        selectedVirus[curCnt] = i;
        usedVirus[i] = true;
        SelectVirus(curCnt+1, curIndex+1);
        usedVirus[i] = false;
    }
}

int main(void) {

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    selectedVirus.resize(M);
    curLab.resize(N);
    cost.resize(N);

    for(int i=0;i<N;i++) {
        curLab[i].resize(N);
        cost[i].resize(N);
        for(int j=0;j<N;j++) {
            cin >> curLab[i][j];
            if (curLab[i][j] == 2) virusPos.push_back({i,j});
            cost[i][j] = -1;
        }
    }

    int virusCnt = virusPos.size();
    usedVirus.resize(virusCnt);
    for(int i=0;i<virusCnt;i++) usedVirus[i] = false;
    virusResult.resize(virusCnt);
    for(int i=0;i<virusCnt;i++) {
        virusResult[i].resize(N);
        for(int y=0;y<N;y++) {
            virusResult[i][y].resize(N);
            for(int x=0;x<N;x++) virusResult[i][y][x] = -1;
        }
    }
    
    for(int i=0;i<virusCnt;i++) DFS(i, virusPos[i].first, virusPos[i].second, 0);

    SelectVirus(0, 0);
    cout << ans;
}