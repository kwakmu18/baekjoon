#include <bits/stdc++.h>

using namespace std;

int getGCD(int a, int b) {
    if (a==0) return b;
    else if (b==0) return a;
    if (a<b) return getGCD(a,b%a);
    else return getGCD(a%b,b);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, M, N, x, y, cnt;
    bool flag=true;
    cin >> T;
    while (T--) {
        cin >> M >> N >> x >> y;
        int lcm=(M*N)/getGCD(M,N);
        int i=0, temp=0;
        flag=true;
        while (temp<=lcm) {
            temp=M*i+x;
            if ((temp-y)%N==0) {
                cout << temp << "\n";
                flag=false;
                break;
            }
            i++;
        }
        if (flag) cout << "-1\n";
    }
}