#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k, cnt=0, min_time=99999, nowtime;
    cin >> n >> k;
    if (n>=k) {
        cout << n-k << "\n" << 1;
        return 0;
    }
    queue<pair<int, int>> position;
    vector<int> visited(100001);
    for(int i=0;i<=100000;i++) visited[i]=99999;
    position.push({n, 0});

    while (!position.empty()) {
        pair<int,int> now=position.front();
        position.pop();
        int nowpos=now.first, nowtime=now.second+1;
        if (visited[nowpos]<nowtime) continue;
        visited[nowpos]=nowtime;
        if (nowpos-1==k || nowpos+1==k || nowpos*2==k) {
            if (min_time<nowtime) continue;
            min_time=nowtime;
            cnt++;
        } 
        if (nowpos*2<=k+1) position.push({nowpos*2, nowtime});
        if (nowpos+1<=k+1) position.push({nowpos+1, nowtime});
        if (nowpos>1 && nowpos-1<=k+1) position.push({nowpos-1, nowtime});
    }
    cout << min_time << "\n" << cnt;
}