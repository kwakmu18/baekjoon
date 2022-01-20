//6186 Silver 5
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int pos[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
int main(void) {
    string s;
    int r,c;
    int cnt=0;
    cin >> r >> c;
    vector<vector<bool>> field;
    field.resize(r);
    for(int i=0;i<r;i++) {
        field[i].resize(c);
        cin >> s;
        for(int j=0;j<c;j++) {
            if (s[j]=='#') field[i][j]=true;
            else field[i][j]=false;
        }
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        queue<pair<int,int>> q;
        if (field[i][j]) {
            cnt++;
            q.push({i,j});
            field[i][j]=false;
            while (!q.empty()) {
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++) {
                    int nx=x+pos[k][0], ny=y+pos[k][1];
                    if (nx>=0 && nx<r && ny>=0 && ny<c && field[nx][ny]) {
                        q.push({nx,ny});
                        field[nx][ny]=false;
                    }
                }
            }
        }
    }
    cout << cnt;
}