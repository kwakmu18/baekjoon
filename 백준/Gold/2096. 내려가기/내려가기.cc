#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    int a,b,c,A,B,C,newa,newb,newc,newA,newB,newC;
    int input1, input2, input3;
    int maxValue=0, minValue=1000000;

    cin >> N;
    cin >> a >> b >> c;
    A=a; B=b;C=c;
    N--;
    while (N--) {
        cin >> input1 >> input2 >> input3;
        newa = max(a+input1, b+input1);
        newb = max(a+input2, max(b+input2, c+input2));
        newc = max(b+input3, c+input3);

        a=newa; b=newb; c=newc;
        newA = min(A+input1, B+input1);
        newB = min(A+input2, min(B+input2, C+input2));
        newC = min(B+input3, C+input3);

        A=newA; B=newB; C=newC;
    }
    cout << max(a,max(b,c)) << " " << min(A,min(B,C));
}