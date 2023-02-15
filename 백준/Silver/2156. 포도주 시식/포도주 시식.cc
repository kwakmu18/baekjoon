#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> wine(n+1);
    wine[0]=0;
    for(int i=1;i<=n;i++) cin >> wine[i];

    if (n<=2) {
        int sum=0;
        for(int i=1;i<=n;i++) sum+=wine[i];
        cout << sum;
        return 0;
    }
    vector<int> notContinued(n+1,0), continued(n+1,0);
    notContinued[1]=wine[1]; notContinued[2]=wine[2];
    continued[1]=wine[1]; continued[2]=wine[1]+wine[2];

    int maxWine = 0;
    for(int i=3;i<=n;i++) {
        notContinued[i] = max(notContinued[i-1], max(continued[i-2]+wine[i], notContinued[i-2]+wine[i]));
        continued[i] = max(continued[i-1], notContinued[i-1]+wine[i]);
        if (notContinued[i]>maxWine) maxWine=notContinued[i];
        if (continued[i]>maxWine) maxWine=continued[i];
    }

    cout << maxWine;
}