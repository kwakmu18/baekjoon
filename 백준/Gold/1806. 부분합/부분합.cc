#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int N, M, input;
    cin >> N >> M;
    vector<long long int> arr(N+1);
    arr[0]=0;
    cin >> arr[1];
    for(int i=2;i<=N;i++) {
        cin >> input;
        arr[i]=arr[i-1]+input;
    }
    int start=0, end=1, min=99999999;
    long long int sum=arr[1];

    while (end<=N) {
        if (sum<M) end++;
        else if (sum>=M) {
            if (min>(end-start)) min=end-start;
            start++;
        }
        sum=arr[end]-arr[start];
    }
    if (min==99999999) cout << 0;
    else cout << min;
}