#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> spf(5000001, 0);
    vector<int> primes;
    for(int i=2;i<=5000000;i++) {
        if (spf[i]==0) {
            spf[i]=i;
            primes.push_back(i);
        }
        for(int j=0;j<primes.size() && i*primes[j]<=5000000; j++) {
            spf[i*primes[j]]=primes[j];
            if (i%primes[j]==0) break;
        }
    }
    int N, input;
    cin >> N;
    while (N--) {
        cin >> input;
        while (input>1) {
            cout << spf[input] << " ";
            input/=spf[input];
        }
        cout << "\n";
    }
}