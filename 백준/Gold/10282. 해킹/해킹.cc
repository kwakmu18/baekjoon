#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n,d,c,a,b,s;
        cin >> n >> d >> c;
        vector<vector<pair<int,int>>> computer(n);
        for(int i=0;i<d;i++) {
            cin >> a >> b >> s;
            computer[b-1].push_back({s,a-1});
        }
        vector<int> times(n);
        for(int i=0;i<n;i++) times[i]=INT_MAX;
        times[c-1]=0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,c-1});
        while (!pq.empty()) {
            int nowtime = -pq.top().first, nowcom = pq.top().second;
            pq.pop();
            if (times[nowcom]<nowtime) continue;
            int size = computer[nowcom].size();
            for(int i=0;i<size;i++) {
                int newtime = nowtime+computer[nowcom][i].first;
                if (times[computer[nowcom][i].second]>newtime) {
                    times[computer[nowcom][i].second]=newtime;
                    pq.push({-newtime, computer[nowcom][i].second});
                }
            }
        }
        int max=0,cnt=0;
        for(int i=0;i<n;i++) {
            if (times[i]!=INT_MAX) {
                cnt++;
                if (max<times[i]) max=times[i];
            }
        }
        cout << cnt << " " << max << "\n";
        times.clear();
        computer.clear();
    }
}