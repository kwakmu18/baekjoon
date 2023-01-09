#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, temp;
    cin >> N >> M;
    int **arr = new int *[N+1];
    arr[0]=new int[N+1];
    for(int i=0;i<=N;i++) arr[0][i]=0;
    arr[1]=new int[N+1];
    arr[1][0]=0;
    cin >> arr[1][1];
    for(int i=2;i<=N;i++) {
        cin >> temp;
        arr[1][i]=arr[1][i-1]+temp;
    }
    for(int i=2;i<=N;i++) {
        arr[i] = new int[N+1];
        arr[i][0]=0;
        cin >> temp;
        arr[i][1]=arr[i-1][1]+temp;
        for(int j=2;j<=N;j++) {
            cin >> temp;
            arr[i][j]=arr[i-1][j]-arr[i-1][j-1]+arr[i][j-1]+temp;
        }
    }

    int x1, y1, x2, y2;
    while (M--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1-1]+arr[x1-1][y1-1] << "\n";
        }
}