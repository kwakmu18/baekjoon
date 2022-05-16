#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    long long innum;
    cin >> innum;
    if (innum<=2) {
        cout << 1;
        return 0;
    }
    long long left=1, right=200000, mid;
    while (left<=right) {
        mid=(left+right)/2;
        long long midsum=mid*(mid+1)/2, midp1sum=(mid+1)*(mid+2)/2;
        if (innum>=midsum && innum<midp1sum) break;
        else if (innum<midsum) right=mid-1;
        else left=mid+1;
    }
    cout << mid;
}