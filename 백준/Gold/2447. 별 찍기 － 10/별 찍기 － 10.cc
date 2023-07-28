#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX_SIZE 2187

using namespace std;

bool stars[MAX_SIZE][MAX_SIZE];

void solve(int N, int y, int x) {
    if (N==3) {
        stars[y][x] = stars[y][x+1] = stars[y][x+2] = true;
        stars[y+1][x] = stars[y+1][x+2] = true;
        stars[y+2][x] = stars[y+2][x+1] = stars[y+2][x+2] = true;
    }
    else {
        N/=3;
        solve(N, y, x);
        solve(N, y+N, x);
        solve(N, y+2*N, x);
        solve(N, y, x+N);
        solve(N, y+2*N, x+N);
        solve(N, y, x+2*N);
        solve(N, y+N, x+2*N);
        solve(N, y+2*N, x+2*N);
    }
}

int main(void) {
    fastio;
    int N;
    cin >> N;
    solve(N,0,0);

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) cout << (stars[i][j]==true ? '*':' ');
        cout << "\n";
    }
}