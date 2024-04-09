#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int arr[10000];

void postorder(int left, int right) {
    if (left>=right) return;
    int idx = left+1;
    while (idx < right) {
        if (arr[left] < arr[idx]) break;
        idx++;
    }

    postorder(left+1, idx);
    postorder(idx, right);
    cout << arr[left] << "\n";
}

int main(void) {
    fastio;
    
    int value, idx=0;
    while (true) {
        cin >> value;
        if (cin.eof()) {
            break;
        }
        arr[idx++] = value;
    }
    postorder(0, idx);
}