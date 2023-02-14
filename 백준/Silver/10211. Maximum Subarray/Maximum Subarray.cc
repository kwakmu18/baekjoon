#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, N, input;
    cin >> T;

    while (T--) {
        cin >> N;
        vector<int> numbers(N+1);
        numbers[0]=0;
        cin >> numbers[1];
        for(int i=2;i<=N;i++) {
            cin >> input;
            numbers[i] = numbers[i-1] + input;
        }
        int maxSum = -99999999;
        for(int i=0;i<=N;i++) {
            
            for(int j=i+1;j<=N;j++) {
                int newSum = numbers[j]-numbers[i];
                if (newSum>maxSum) maxSum = newSum;
            }
        }
        cout << maxSum << "\n";
    }
}