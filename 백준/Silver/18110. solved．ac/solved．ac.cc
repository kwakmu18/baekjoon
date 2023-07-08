#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> scores;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if (N==0) {
        cout << "0";
        return 0;
    }
    scores.resize(N);
    for(int i=0;i<N;i++) cin >> scores[i];
    sort(scores.begin(), scores.end());
    int cnt = round(1.0*N*0.15);
    double total = 0;
    for(int i=cnt;i<N-cnt;i++) total+=scores[i];
    cout << (int)round(total/(N-2*cnt));
}