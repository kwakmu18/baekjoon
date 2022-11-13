#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> rope(n);
    for(int i=0;i<n;i++) cin >> rope[i];
    sort(rope.begin(), rope.end());
    int max=rope[n-1];
    for(int i=0;i<n-1;i++) {
        if (rope[i]*(n-i)>max) max=rope[i]*(n-i);
    }
    cout << max;
}