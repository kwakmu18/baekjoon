#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, input;
    cin >> N >> M;
    int *arr=new int[N+1];
    long long *remain=new long long[M]{0};
    arr[0]=0;
    cin >> input;
    arr[1]=input%M;
    for(int i=2;i<=N;i++) {
        cin >> input;
        arr[i]= ((arr[i-1]%M)+(input%M))%M;
        remain[arr[i]]++;
    }
    remain[arr[0]]++;
    remain[arr[1]]++;
    long long int cnt=0;
    for(int i=0;i<M;i++) cnt+=remain[i]*(remain[i]-1)/2;
    cout << cnt;
}