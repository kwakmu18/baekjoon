#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> numbers;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    numbers.resize(N);
    for(int i=0;i<N;i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    int left = 0, right = 1;
    int now, ans = INT_MAX;
    while (right!=N) {
        //cout << "left : " << left << ", right : " << right << "\n";
        now = numbers[right] - numbers[left];
        if (now==M) {
            cout << now;
            return 0;
        }
        else if (now>M) {
            if (now<ans) ans=now;
            left++;
        }
        else if (now<M) right++;

    }
    cout << ans;
}