#include <bits/stdc++.h>

using namespace std;

int len;
map<char, int> alpha;
map<char, int> visited;
vector<char> nowAlpha;

void dfs(int cnt) {
    if (cnt==len) {
        for(int i=0;i<len;i++) cout << nowAlpha[i];
        cout << "\n";
        return;
    }

    for(auto i = alpha.begin();i!=alpha.end();i++) {
        char nowChar = (*i).first;
        int nowCnt = (*i).second;
        if (visited[nowChar]>=nowCnt) continue;
        visited[nowChar]++;
        nowAlpha.push_back(nowChar);
        dfs(cnt+1);
        nowAlpha.pop_back();
        visited[nowChar]--;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    string line;
    while (T--) {
        cin >> line;
        len = line.length();
        for(int i=0;i<len;i++) {
            if (!alpha[line[i]]) alpha[line[i]]=1;
            else alpha[line[i]]++;
        }
        dfs(0);
        alpha.clear();
        visited.clear();
        nowAlpha.clear();
    }
}