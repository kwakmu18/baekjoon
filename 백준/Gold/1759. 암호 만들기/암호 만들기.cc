#include <bits/stdc++.h>

using namespace std;

int L, C;

vector<char> alphabets;
vector<bool> visited;
vector<char> usedAlphabets;

void dfs(int vowel, int consonant) {
    if (vowel+consonant==L) {
        if (vowel==0 || consonant<2) return;
        for(int i=0;i<L;i++) cout << usedAlphabets[i];
        cout << "\n";
        return;
    }

    for(int i=0;i<C;i++) {
        if (visited[i] || (!usedAlphabets.empty() && usedAlphabets.back()>alphabets[i])) continue;
        visited[i]=true;
        usedAlphabets.push_back(alphabets[i]);
        switch (alphabets[i]) {
            case 'a':
            case 'i':
            case 'e':
            case 'o':
            case 'u':
                dfs(vowel+1, consonant);
                break;
            default:
                dfs(vowel, consonant+1);
        }
        visited[i]=false;
        usedAlphabets.pop_back();
    }
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> L >> C;
    alphabets.resize(C);
    visited.resize(C);
    for(int i=0;i<C;i++) {
        cin >> alphabets[i];
        visited[i]=false;
    }
    sort(alphabets.begin(), alphabets.end());
    dfs(0,0);

}