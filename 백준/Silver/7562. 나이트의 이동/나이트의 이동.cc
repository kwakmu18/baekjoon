#include <bits/stdc++.h>

using namespace std;

int pos[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int l, srcx, srcy, dstx, dsty;
        cin >> l;
        int **time = new int *[l];
        for(int i=0;i<l;i++) {
            time[i]=new int[l];
            for(int j=0;j<l;j++) time[i][j]=99999999;
        }
        cin >> srcx >> srcy;
        cin >> dstx >> dsty;
        time[srcx][srcy]=0;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{srcx, srcy}});
        while (!pq.empty()) {
            int nowx=pq.top().second.first, nowy=pq.top().second.second, nowtime=-pq.top().first;
            pq.pop();
            if (nowtime>time[nowx][nowy]) continue;
            for(int i=0;i<8;i++) {
                int movex=nowx+pos[i][0], movey=nowy+pos[i][1];
                if (movex>=0 && movey>=0 && movex<l && movey<l) {
                    int movetime = nowtime+1;
                    if (movetime<time[movex][movey]) {
                        time[movex][movey]=movetime;
                        pq.push({-movetime,{movex,movey}});
                    }
                }
            }
        }
        cout << time[dstx][dsty] << "\n";
        for(int i=0;i<l;i++) delete[] time[i];
        delete[] time;
    }
}