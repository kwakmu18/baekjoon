#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin >> arr[i];
    int start=0, end=0, sum=arr[0], cnt=0;

    while (end<N) {
        if (sum<M) sum+=arr[++end];
        else if (sum==M) {
            cnt++;
            sum-=arr[start++];
        }
        else sum-=arr[start++];
    }
    cout << cnt;
}