#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int,int> visited;
map<int,int> arr;
vector<int> visitedNumbers;

void dfs(int cnt) {
    if (cnt==M) {
        for(int i=0;i<M;i++) cout << visitedNumbers[i] << " ";
        cout << "\n";
    }
    else if (cnt>M) return;

    for(auto i = arr.begin(); i!=arr.end(); i++) {
        int nowNumber = (*i).first, nowCnt = (*i).second;
        if (visited[nowNumber]>=nowCnt) continue;
        visited[nowNumber]++;
        visitedNumbers.push_back(nowNumber);
        dfs(cnt+1);
        visited[nowNumber]--;
        visitedNumbers.pop_back();
    }
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int input;

    for(int i=0;i<N;i++) {
        cin >> input;
        if (!arr[input]) arr[input]=1;
        else arr[input]++;
        visited[input]=0;
    }

    dfs(0);

    return 0;
}