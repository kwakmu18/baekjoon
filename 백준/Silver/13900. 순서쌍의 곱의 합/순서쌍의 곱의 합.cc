#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ull;
int N, temp;
vector<ull> prefix_sum;
vector<ull> number;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    prefix_sum.resize(N+1);
    number.resize(N);
    prefix_sum[0]=0;
    for(int i=1;i<=N;i++) {
        cin >> number[i-1];
        prefix_sum[i] = number[i-1] + prefix_sum[i-1];
    }

    ull total = 0;
    for(int i=0;i<N;i++) {
        total += number[i] * (prefix_sum[N]-prefix_sum[i+1]);
    }
    cout << total;
}