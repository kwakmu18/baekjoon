#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, i, j, k;
    cin >> N >> M;
    
    vector<int> basket(N+1,0);

    while (M--) {
        cin >> i >> j >> k;
        for(int index=i;index<=j;index++) basket[index]=k;
    }
    
    for(int i=1;i<=N;i++) cout << basket[i] << " ";
}