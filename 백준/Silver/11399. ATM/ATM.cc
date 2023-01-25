#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> times(N);
    for(int i=0;i<N;i++) {
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    int sum=times[0];
    for(int i=1;i<N;i++) {
        times[i]=times[i]+times[i-1];
        sum+=times[i];
    }
    cout << sum;
}