#include <bits/stdc++.h>

using namespace std;

void print(int a) {
    for(int i=0;i<a;i++) cout << 1;
}

int main(void) {
    long long a,b;
    cin >> a >> b;
    if (a==b) print(a);
    else {
        if (a>b) swap(a, b);
        while (true) {
            if (b%a==0) {
                print(a);
                return 0;
            }
            else b%=a;
            if (a>b) swap(a,b);
        }
    }
}