#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    int nowHeight;
    cin >> nowHeight;

    stack<pair<int,int>> biggerHeight;
    biggerHeight.push({1,nowHeight});

    cout << "0 ";
    
    for(int i=1;i<N;i++) {
        cin >> nowHeight;
        while (!biggerHeight.empty() && biggerHeight.top().second<=nowHeight) biggerHeight.pop();

        if (biggerHeight.empty()) {
            cout << "0 ";
        }
        else {
            cout << biggerHeight.top().first << " ";
        }
        biggerHeight.push({i+1, nowHeight});
    }


}