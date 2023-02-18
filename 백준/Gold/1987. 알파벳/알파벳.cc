#include <bits/stdc++.h>

using namespace std;

int R,C, maxCnt;
int dydx[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<char>> board;
vector<bool> visited;

void dfs(int y, int x, int cnt) {
    if (cnt>maxCnt) maxCnt=cnt;

    for(int i=0;i<4;i++) {
        int newY = y+dydx[i][0], newX = x+dydx[i][1];
        if (newY<0 || newY>=R || newX<0 || newX>=C) continue;
        int newAlpha = board[newY][newX]-'A';
        if (visited[newAlpha]) continue;
        visited[newAlpha]=true;
        dfs(newY, newX, cnt+1);
        visited[newAlpha]=false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C;
    board.resize(R);

    string line;
    for(int i=0;i<R;i++) {
        board[i].resize(C);
        cin >> line;
        for(int j=0;j<C;j++) board[i][j]=line[j];
    }

    visited.resize(26);
    for(int i=0;i<26;i++) visited[i]=false;
    visited[board[0][0]-'A']=true;
    dfs(0,0,1);
    cout << maxCnt;
}