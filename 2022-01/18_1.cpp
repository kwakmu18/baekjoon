//Problem 1312
#include <iostream>
using namespace std;
int main(void) {
    int a, b, n, division, ans;
    cin >> a >> b >> n;
    n++;
    while (n--) {
        division=a/b;
        a-=b*division;
        a*=10;
    }
    cout << division;
}