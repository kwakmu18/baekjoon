#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string clothName, clothType;
        unordered_map<string, vector<string>> clothes;
        while (n--) {
            cin >> clothName >> clothType;
            clothes[clothType].push_back(clothName);
        }
        int ans=1;
        for(auto i=clothes.begin();i!=clothes.end();i++) ans*=(*i).second.size()+1;
        cout << ans-1 << "\n";
    }
}