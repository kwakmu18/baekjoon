#include <bits/stdc++.h>

using namespace std;

int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
vector<int> digits;
int digitsCnt = 1, numCnt=0, N;
bool done = false;

void dfs(int cnt) {
    if (done) return;
    if (cnt==digitsCnt) {
        if (numCnt==N) {
            for(int i=0;i<digitsCnt;i++) cout << digits[i];
            done=true;
        }
        else numCnt++;
        return;
    }

    for(int i=0;i<10;i++) {
        if (digits.empty() && i==0) continue;
        else if (!digits.empty() && digits.back()<=i) break;
        digits.push_back(i);
        dfs(cnt+1);
        digits.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    if (N<=10) {
        cout << N;
        return 0;
    }
    else if (N>=1023) {
        cout << -1;
        return 0;
    }
    N--;
    while (numCnt<=N) {
        if (done) break;
        dfs(0);
        digitsCnt++;
    }

}