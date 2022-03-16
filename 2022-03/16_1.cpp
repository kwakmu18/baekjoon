#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    int d=a*b*c;
    int *num=new int[10]{0};
    while (d>9) {
        int e=d%10;
        num[e]++;
        d/=10;
    }
    num[d]++;
    for(int i=0;i<10;i++) cout << num[i] << "\n";
}