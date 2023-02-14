#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;
vector<bool> visited;
vector<int> visitedNumbers;

void dfs(int cnt) {
    if (cnt==M) {
        for(int i=0;i<M;i++) cout << visitedNumbers[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=0;i<N;i++) {
        if (visited[i]) continue;
        visitedNumbers.push_back(arr[i]);
        visited[i]=true;
        dfs(cnt+1);
        visited[i]=false;
        visitedNumbers.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    arr.resize(N);
    visited.resize(N);

    for(int i=0;i<N;i++) {
        cin >> arr[i];
        visited[i]=false;
    }

    sort(arr.begin(), arr.end());

    dfs(0);
    
    return 0;
}