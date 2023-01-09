#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, sum=0, input;
    cin >> N >> K;
    int *base=new int[N];
    cin >> base[0];
    for(int i=1;i<N;i++) {
        cin >> input;
        base[i]=base[i-1]+input;
    }
    int max=base[K-1];
    for(int i=K;i<N;i++) {
        int nowsum = base[i]-base[i-K];
        if (max<nowsum) max=nowsum;
    }
    cout << max;
}