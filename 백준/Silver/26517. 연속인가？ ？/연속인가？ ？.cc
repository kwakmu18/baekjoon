#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long long k, a, b, c, d;
    cin >> k;
    cin >> a >> b >> c >> d;
    if ((a*k+b) == (c*k+d)) cout << "Yes " << a*k+b;
    else cout << "No";
    return 0;
}