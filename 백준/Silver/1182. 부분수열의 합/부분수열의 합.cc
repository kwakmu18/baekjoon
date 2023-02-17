#include <bits/stdc++.h>

using namespace std;

int N, S, totalCnt;
vector<int> numbers;
vector<bool> visited;
vector<int> nowNumbers;

void dfs(int sum, int befIndex) {
    if (sum==S && befIndex!=-1) totalCnt++;

    for(int i=0;i<N;i++) {
        if (visited[i] || befIndex>=i) continue;
        nowNumbers.push_back(numbers[i]);
        visited[i]=true;
        dfs(sum+numbers[i], i);
        visited[i]=false;
        nowNumbers.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> S;

    numbers.resize(N);
    visited.resize(N);

    for(int i=0;i<N;i++) {
        cin >> numbers[i];
        visited[i] = false;
    }

    dfs(0,-1);
    cout << totalCnt;

    return 0;
}