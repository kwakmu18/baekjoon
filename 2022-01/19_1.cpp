//1476
#include <iostream>
using namespace std;
int main(void) {
    int e=1, s=1, m=1, a, b, c, year=1;
    cin >> a >> b >> c;
    while (e!=a || s!=b || m!=c) {
        e+=1, s+=1, m+=1;
        if (e>15) e-=15;
        if (s>28) s-=28;
        if (m>19) m-=19;
        year++;
    }
    cout << year;
}