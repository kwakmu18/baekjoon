#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, input, ans=0;
    cin >> N;
    if (N==1) {
        cout << 0;
        return 0;
    }
    priority_queue<int> pq;
    for(int i=0;i<N;i++) {
        cin >> input;
        pq.push(-input);
    }
    while (true) {
        int now=-pq.top();
        pq.pop();
        now-=pq.top();
        pq.pop();
        ans+=now;
        if (pq.empty()) break;
        pq.push(-now);
    }
    cout << ans;
}