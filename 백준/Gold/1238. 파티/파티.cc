#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M,X,A,B,T,nowtime,nowtown;
    cin >> N >> M >> X;
    vector<vector<pair<int,int>>> road(N);
    vector<vector<pair<int,int>>> reverse_road(N);
    for(int i=0;i<M;i++) {
        cin >> A >> B >> T;
        road[A-1].push_back({T,B-1});
        reverse_road[B-1].push_back({T,A-1});
    }
    priority_queue<pair<int,int>> pq;
    vector<int> length(N), reverse_length(N);
    for(int i=0;i<N;i++) {
        if (i==X-1) length[i]=0;
        else length[i]=99999999;
    }
    pq.push({0,X-1});
    while (!pq.empty()) {
        pair<int,int> now=pq.top();
        pq.pop();
        nowtime = now.first; nowtown = now.second;
        int size=road[nowtown].size();
        for(int j=0;j<size;j++) {
            if (length[road[nowtown][j].second]>nowtime+road[nowtown][j].first) {
                length[road[nowtown][j].second]=nowtime+road[nowtown][j].first;
                pq.push({nowtime+road[nowtown][j].first, road[nowtown][j].second});
            }
        }
    }
    for(int i=0;i<N;i++) {
        if (i==X-1) reverse_length[i]=0;
        else reverse_length[i]=99999999;
    }
    pq.push({0,X-1});
    while (!pq.empty()) {
        pair<int,int> now=pq.top();
        pq.pop();
        nowtime = now.first; nowtown = now.second;
        int size=reverse_road[nowtown].size();
        for(int j=0;j<size;j++) {
            if (reverse_length[reverse_road[nowtown][j].second]>nowtime+reverse_road[nowtown][j].first) {
                reverse_length[reverse_road[nowtown][j].second]=nowtime+reverse_road[nowtown][j].first;
                pq.push({nowtime+reverse_road[nowtown][j].first, reverse_road[nowtown][j].second});
            }
        }
    }
    int max=0;
    for(int i=0;i<N;i++) {
        if (max<length[i]+reverse_length[i]) max=length[i]+reverse_length[i];
    }
    cout << max;
}