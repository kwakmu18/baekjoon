#include <iostream>
#define DIV 1000000007
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    long long n1=1, n2=1, n3;
    cin >> n;
    for(int i=3;i<=n;i++) {
        n3=((n1%DIV)+(n2%DIV))%DIV;
        n1=n2; n2=n3;
    }
    cout << n3 << " " << n-2;
}