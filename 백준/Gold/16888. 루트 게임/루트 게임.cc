#include <bits/stdc++.h>
#define SIZE 1000000

using namespace std;
vector<bool> game(SIZE+1);

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //koosaga : 1, cubelover : 2
    game[2] = false;
    int i = 1;
    while (i*i<=SIZE) {
        game[i*i] = true;
        i++;
    }
    for(i=1;i<=SIZE;i++) {
        if (!game[i]) {
            int j = 1;
            while (i+j*j<=SIZE) {
                game[i+j*j] = true;
                j++;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << (game[n] ? "koosaga\n":"cubelover\n");
    }
}