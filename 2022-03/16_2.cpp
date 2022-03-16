#include <iostream>
#include <map>
using namespace std;
int num[52][52][52];
int w(int a, int b, int c) {
    if (a<=0 || b<=0 || c<=0) return num[51][51][51];
    else if (a>20 || b>20 || c>20) {
        if (num[20][20][20]==0) num[20][20][20]=w(20,20,20);
        return num[20][20][20];
    }
    else if (a<b && b<c ) {
        if (num[a][b][c-1]==0) num[a][b][c-1]=w(a,b,c-1);
        if (num[a][b-1][c-1]==0) num[a][b-1][c-1]=w(a,b-1,c-1);
        if (num[a][b-1][c]==0) num[a][b-1][c]=w(a,b-1,c);
        return num[a][b][c-1]+num[a][b-1][c-1]-num[a][b-1][c];
    }
    else {
        //w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        if (num[a-1][b][c]==0) num[a-1][b][c]=w(a-1,b,c);
        if (num[a-1][b-1][c]==0) num[a-1][b-1][c]=w(a-1,b-1,c);
        if (num[a-1][b][c-1]==0) num[a-1][b][c-1]=w(a-1,b,c-1);
        if (num[a-1][b-1][c-1]==0) num[a-1][b-1][c-1]=w(a-1,b-1,c-1);
        return num[a-1][b][c]+num[a-1][b-1][c]+num[a-1][b][c-1]-num[a-1][b-1][c-1];
    }
}
int main(void) {
    int a, b, c;
    num[51][51][51]=1;
    while (true) {
        cin >> a >> b >> c;
        if (a==-1 && b==-1 && c==-1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << "\n";
    }
}