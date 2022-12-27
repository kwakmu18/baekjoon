#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, cnt=0, min_time=99999, nowtime;
    cin >> n >> k;
    if (n>=k) {
        cout << n-k << endl;
        for(int i=n;i>=k;i--) cout << i << " ";
        return 0;
    }
    queue<pair<pair<int, int>,vector<int>>> position;
    vector<int> visited(100001);
    for(int i=0;i<=100000;i++) visited[i]=99999;
    vector<int> base;
    position.push({{n, 0},base});
    while (!position.empty()) {
        pair<pair<int,int>,vector<int>> now=position.front();
        position.pop();
        int nowpos=now.first.first, nowtime=now.first.second+1;
        vector<int> nowvector=now.second;
        if (visited[nowpos]<nowtime) continue;
        visited[nowpos]=nowtime;
        nowvector.push_back(nowpos);
        if (nowpos*2==k) {
            cout << nowtime << endl;
            for(int i=0;i<nowtime;i++) cout << nowvector[i] << " ";
            cout << nowpos*2;
            return 0;
        }
        else if (nowpos-1==k) {
            cout << nowtime << endl;
            for(int i=0;i<nowtime;i++) cout << nowvector[i] << " ";
            cout << nowpos-1;
            return 0;
        }
        else if (nowpos+1==k) {
            cout << nowtime << endl;
            for(int i=0;i<nowtime;i++) cout << nowvector[i] << " ";
            cout << nowpos+1;
            return 0;
        }

        if (nowpos>=1 && nowpos*2<=k+1) position.push({{nowpos*2, nowtime},nowvector});
        if (nowpos+1<=k+1) position.push({{nowpos+1, nowtime},nowvector});
        if (nowpos>1 && nowpos-1<=k+1) position.push({{nowpos-1, nowtime},nowvector});
    }
}