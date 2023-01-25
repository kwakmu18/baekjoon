#include <bits/stdc++.h>

using namespace std;

int *fibo;

int calc(int n) {
    if (n<=3) return n;
    else if (fibo[n]==0) {
        if (fibo[n-2]==0) {
            fibo[n-2]=(calc(n-3)%10007+calc(n-4)%10007)%10007;
        }
        if (fibo[n-1]==0) {
            fibo[n-1]=(calc(n-2)%10007+calc(n-3)%10007)%10007;
        }
        return fibo[n]=(calc(n-1)%10007+calc(n-2)%10007)%10007;
    }
    return fibo[n]%10007;

}

int main(void) {
    int n;
    cin >> n;
    fibo = new int[n+1]{0};
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=2;
    cout << calc(n);
}