#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> triangle(N), maxScore(N);
    
    for(int i=0;i<N;i++) {
        triangle[i].resize(i+1);
        maxScore[i].resize(i+1);
        for(int j=0;j<(i+1);j++) {
            cin >> triangle[i][j];
            maxScore[i][j]=0;
        }
    }

    if (N==1) {
        cout << triangle[0][0];
        return 0;
    }

    maxScore[0][0] = triangle[0][0];
    maxScore[1][0] = triangle[0][0] + triangle[1][0];
    maxScore[1][1] = triangle[0][0] + triangle[1][1];

    for(int i=2;i<N;i++) {
        maxScore[i][0] = maxScore[i-1][0] + triangle[i][0];
        for(int j=1;j<i;j++) {
            maxScore[i][j] = max(maxScore[i-1][j-1], maxScore[i-1][j]) + triangle[i][j];
        }
        maxScore[i][i] = maxScore[i-1][i-1] + triangle[i][i];
    }

    int ans = 0;
    for(int i=0;i<N;i++) {
        if (maxScore[N-1][i]>ans) ans=maxScore[N-1][i];
    }

    cout << ans;
}