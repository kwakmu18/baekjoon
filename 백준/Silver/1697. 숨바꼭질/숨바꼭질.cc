#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    if (n>=k) {
        cout << n-k;
        return 0;
    }
    queue<pair<int, int>> position;
    vector<bool> visited(100001);
    for(int i=0;i<=100000;i++) visited[i]=false;
    position.push({n, 0});

    while (!position.empty()) {
        pair<int,int> now=position.front();
        position.pop();
        int nowpos=now.first, nowtime=now.second+1;
        if (visited[nowpos]) continue;
        visited[nowpos]=true;
        if (nowpos-1==k || nowpos+1==k || nowpos*2==k) {
            cout << nowtime;
            return 0;
        } 
        if (nowpos*2<=k+1) position.push({nowpos*2, nowtime});
        if (nowpos+1<=k+1) position.push({nowpos+1, nowtime});
        if (nowpos>1 && nowpos-1<=k+1) position.push({nowpos-1, nowtime});
    }
}