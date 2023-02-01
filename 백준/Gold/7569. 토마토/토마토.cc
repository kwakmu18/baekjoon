#include <bits/stdc++.h>

using namespace std;



typedef struct Point {
    int x,y,z;
}point;

bool function(pair<int,point> p1,pair<int,point> p2 ) {
    if (p1.first<p2.first) return true;
}

int pos[6][3]={
    {0,0,-1}, {0,0,1},
    {-1,0,0}, {0,-1,0},
    {1,0,0}, {0,1,0}
};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M,N,H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> tomato(H);
    vector<vector<vector<int>>> days(H);
    queue<pair<int,struct Point>> pq;

    for(int i=0;i<H;i++) {
        tomato[i].resize(N);
        days[i].resize(N);
        for(int j=0;j<N;j++) {
            tomato[i][j].resize(M);
            days[i][j].resize(M);
            for(int k=0;k<M;k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k]==1) {
                    point p;
                    p.x=k; p.y=j; p.z=i;
                    pq.push({0,p});
                    days[i][j][k]=0;
                }
                else days[i][j][k]=99999999;
            }
        }
    }
    int totaldays=0;
    while (!pq.empty()) {
        int nowx=pq.front().second.x, nowy=pq.front().second.y, nowz=pq.front().second.z;
        int nowday=pq.front().first;
        pq.pop();
        if (days[nowz][nowy][nowx]<nowday) continue;

        for(int i=0;i<6;i++) {
            int newx=nowx+pos[i][0], newy=nowy+pos[i][1], newz=nowz+pos[i][2];
            int newday=nowday+1;
            if (newx>=0 && newy>=0 && newz>=0 && newx<M && newy<N && newz<H && tomato[newz][newy][newx]==0) {
                tomato[newz][newy][newx]=1;
                if (days[newz][newy][newx]>newday) {
                    days[newz][newy][newx]=newday;
                    if (totaldays<newday) totaldays=newday;
                    point p;
                    p.x=newx; p.y=newy; p.z=newz;
                    pq.push({newday,p});
                }
            }
        }
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                if (tomato[i][j][k]==0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << totaldays;
}