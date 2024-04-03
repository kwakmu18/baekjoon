#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int pos[4][2] = {{1,0}, {0,1}, {0,-1},{-1,0}};

int main(void) {
    int N, M;
    cin >> N >> M;

    bool field[N][M];
    int visited[N][M][2];


    string line;
    for(int i=0;i<N;i++) {
        cin >> line;
        for(int j=0;j<M;j++) {
            field[i][j] = line[j]-'0';
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }
    visited[0][0][false] = 1;
    queue<tuple<int,int,bool>> q;

    q.push({0,0,false});
    while (!q.empty()) {
        bool crashed = get<2>(q.front());
        int nowY = get<0>(q.front()), nowX = get<1>(q.front());
        q.pop();
        if (nowY==N-1 && nowX==M-1) {
            cout << min(visited[N-1][M-1][0] ? visited[N-1][M-1][0]:INT_MAX, visited[N-1][M-1][1] ? visited[N-1][M-1][1]:INT_MAX);
            return 0;
        }

        for(int i=0;i<4;i++) {
            int newY = nowY + pos[i][0], newX = nowX + pos[i][1];
            if (newY<0 || newX<0 || newY>=N || newX>=M) {
                continue;
            }

            if (!field[newY][newX] && visited[newY][newX][crashed]==0) {
                visited[newY][newX][crashed] = visited[nowY][nowX][crashed]+1;
                q.push({newY, newX,crashed});
            }
            else if (!crashed && field[newY][newX]){
                visited[newY][newX][true] = visited[nowY][nowX][false]+1;
                q.push({newY, newX,true});
            }
        }
    }
    cout << -1;
    return 0;
}