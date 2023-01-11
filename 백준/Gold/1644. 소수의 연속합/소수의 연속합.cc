#include <bits/stdc++.h>

using namespace std;

int main(void) {
    bool *primecheck = new bool[4000001]{0};
    vector<int> prime;
    prime.push_back(0);
    int index=0;
    for(int i=2;i<=4000000;i++) {
        if (!primecheck[i]) {
            for(int j=i*2;j<=4000000;j+=i) primecheck[j]=true;
            prime.push_back(prime[index]+i);
            index++;
        }
    }
    int N;
    cin >> N;
    int start=0, end=1, sum=prime[1], cnt=0;
    while (end<=index) {
        if (sum<N) end++;
        else if (sum==N) {
            cnt++;
            start++;
        }
        else {
            start++;
        }
        sum=prime[end]-prime[start];
    }
    cout << cnt;
}