#include <iostream>

using namespace std;

int call1=0;

int fibo1(int n) {
    if (n<=2) {
        call1++;
        return 1;
    }
    return fibo1(n-2)+fibo1(n-1);
}


int main(void) {
    int n;
    cin >> n;
    fibo1(n);
    cout << call1 << " " << n-2;
}