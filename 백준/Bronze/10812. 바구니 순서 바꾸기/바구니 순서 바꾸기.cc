#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, i, j, k;
    cin >> N >> M;

    vector<int> basket;
    for(int i=1;i<=N;i++) basket.push_back(i);

    while (M--) {
        cin >> i >> j >> k;
        rotate(basket.begin()+(i-1), basket.begin()+(k-1), basket.begin()+j);
    }

    for(int i=0;i<N;i++) cout << basket[i] << " ";
}