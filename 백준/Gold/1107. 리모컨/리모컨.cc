#include <bits/stdc++.h>

using namespace std;

int main(void) {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, input;
    cin >> N;
    cin >> M;
    bool button[10]{0,};
    for(int i=0;i<M;i++) {
        cin >> input;
        button[input]=true;
    }
    vector<int> enabledButton;
    for(int i=0;i<10;i++) {
        if (!button[i]) enabledButton.push_back(i);
    }
    int min = 1000000, size=enabledButton.size();
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while (!pq.empty()) {
        int nowChannel = -pq.top().first, nowCnt = pq.top().second;
        pq.pop();
        for(int i=0;i<size;i++) {
            int newChannel = nowChannel*10+enabledButton[i], newCnt = nowCnt+1;
            if (newCnt + abs(N-newChannel)<=min) {
                min = newCnt + abs(N-newChannel);
                pq.push({-newChannel, newCnt});
            }
        }
    }
    if (min>abs(N-100)) cout << abs(N-100);
    else cout << min;
}