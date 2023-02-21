#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, i, j;
    cin >> N >> M;

    vector<int> basket(N+1);
    for(int i=1;i<=N;i++) basket[i]=i;

    while (M--) {
        cin >> i >> j;
        swap(basket[i], basket[j]);
    }

    for(int i=1;i<=N;i++) cout << basket[i] << " ";
}