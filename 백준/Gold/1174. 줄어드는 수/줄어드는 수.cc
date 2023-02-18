#include <bits/stdc++.h>

using namespace std;

int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
vector<int> digits;
int digitsCnt = 1, numCnt=0, N;
bool done = false, flag=false;

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
        //if (digits.empty() && i==0) continue;
        if (!digits.empty() && digits.back()<=i) break;
        digits.push_back(i);
        dfs(cnt+1);
        digits.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    N--;
    while (numCnt<=N) {
        if (done) break;
        else if (digitsCnt==11) {
            cout << -1;
            break;
        }
        dfs(0);
        digitsCnt++;
    }

}