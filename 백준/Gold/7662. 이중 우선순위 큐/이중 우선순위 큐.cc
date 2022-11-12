#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    multiset<int> ms;
    int t, inscnt, input;
    char select;
    cin >> t;
    while (t--) {
        ms.clear();
        multiset<int>::iterator start=ms.begin();
        multiset<int>::iterator end=ms.end();
        cin >> inscnt;
        while (inscnt--) {
            cin >> select;
            switch (select) {
                case 'I':
                    cin >> input;
                    ms.insert(input);
                    break;
                case 'D':
                    cin >> input;
                    if (ms.size()==0) continue;
                    if (input==-1) {
                        ms.erase(ms.begin());
                    }
                    else {
                        ms.erase(--ms.end());
                    }
                    break;
                default:break;
            }
        }
        if (ms.size()==0) cout << "EMPTY\n";
        else cout << *(--ms.end()) << " " << *ms.begin() << "\n";
    }
}