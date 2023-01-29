#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string input;
    int N,M;
    cin >> N >> M;
    unordered_set<string> keyword;
    for(int i=0;i<N;i++) {
        cin >> input;
        keyword.insert(input);
    }
    while (M--) {
        cin >> input;
        int inputLength = input.length(), inputIndex=0, remainWord=N;
        while (true) {
            string word="";
            while (inputIndex<inputLength && input[inputIndex]!=',') {
                word+=input[inputIndex];
                inputIndex++;
            }
            unordered_set<string>::iterator iter = keyword.find(word);
            if (iter!=keyword.end()) {
                N--;
                remainWord--;
                keyword.erase(iter);
            }
            inputIndex++;
            if (inputIndex>=inputLength) break;
        }
        cout << remainWord << "\n";
    }
}