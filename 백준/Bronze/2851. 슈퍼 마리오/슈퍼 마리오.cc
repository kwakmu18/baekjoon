#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int sum=0, input;
    int *arr=new int[10];
    cin >> arr[0];
    for(int i=1;i<10;i++) {
        cin >> input;
        arr[i]=arr[i-1]+input;
    }
    int i=0;
    while (arr[i]<100 && i<10) i++;
    if (abs(100-arr[i])>abs(100-arr[i-1])) cout << arr[i-1];
    else cout << arr[i];
}