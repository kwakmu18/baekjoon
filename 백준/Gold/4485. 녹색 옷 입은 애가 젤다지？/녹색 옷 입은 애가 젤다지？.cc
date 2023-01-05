#include <bits/stdc++.h>

using namespace std;

int pos[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N,problem=1;
    cin >> N;

    while (N!=0) {
        vector<vector<int>> cave(N);
        vector<vector<int>> newcave(N);
        for(int i=0;i<N;i++) {
            cave[i].resize(N);
            newcave[i].resize(N);
            for(int j=0;j<N;j++) {
                cin >> cave[i][j];
                newcave[i][j]=INT_MAX;
            }
        }
        newcave[0][0]=cave[0][0];
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({-cave[0][0],{0,0}});
        while (!pq.empty()) {
            int nowcost=-pq.top().first, nowx=pq.top().second.first, nowy=pq.top().second.second;
            pq.pop();
            if (newcave[nowx][nowy]<nowcost) continue;
            for(int i=0;i<4;i++) {
                int newx=nowx+pos[i][0], newy=nowy+pos[i][1];
                if (newx>=0 && newy>=0 && newx<N && newy<N) {
                    int newcost = nowcost+cave[newx][newy];
                    if (newcave[newx][newy]>newcost) {
                        newcave[newx][newy]=newcost;
                        pq.push({-newcost,{newx,newy}});
                    }
                }
            }
        }
        cout << "Problem " << problem << ": " << newcave[N-1][N-1] << "\n";
        cin >> N;
        problem++;
    }
}