#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (a%b==0) return b;
    else return gcd(b, a%b);
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int base;
    cin >> base;
    for(int i=1;i<n;i++) {
        int num;
        cin >> num;
        if (base>num) cout << base/gcd(base,num) << "/" << num/gcd(base,num) << "\n";
        else if (base==num) cout << "1/1" << "\n";
        else cout << base/gcd(num,base) << "/" << num/gcd(num,base) << "\n";
    }
}