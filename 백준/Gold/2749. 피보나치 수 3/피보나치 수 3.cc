#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

long long fibo[1500000];

int main(void) {
    fastio;

    fibo[0] = 0; fibo[1] = 1;
    for(int i=2;i<1500000;i++) {
        fibo[i] = (fibo[i-1]+fibo[i-2])%1000000;
    }
    long long n;
    cin >> n;

    cout << fibo[n%1500000];

}