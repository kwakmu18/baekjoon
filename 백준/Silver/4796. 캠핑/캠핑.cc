#include <iostream>

using namespace std;

int main(void) {
    int l, p, v, time=1, ans;
    while (true) {
        cin >> l >> p >> v;
        if (l==0 && p==0 && v==0) break;
        ans=(v/p)*l;
        ans+=(v%p)>l ? l : v%p;
        cout << "Case " << time << ": " << ans << "\n";
        time++;
    }
}