#include <bits/stdc++.h>

using namespace std;

int n, k, cnt=1;
vector<int> nowNumbers;
bool flag=false;

void dfs(int sum) {
    if (flag) return;
    if (sum==n) {
        if (cnt==k) {
            int size = nowNumbers.size();
            for(int i=0;i<size;i++) {
                cout << nowNumbers[i];
                if (i!=size-1) cout << "+";
            }
            cout << "\n";
            flag=true;
        }
        else cnt++;
        return;
    }
    else if (sum>n) return;

    nowNumbers.push_back(1);
    dfs(sum+1);
    nowNumbers.pop_back();

    nowNumbers.push_back(2);
    dfs(sum+2);
    nowNumbers.pop_back();

    nowNumbers.push_back(3);
    dfs(sum+3);
    nowNumbers.pop_back();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;

    dfs(0);
    if (!flag) cout << -1;
}