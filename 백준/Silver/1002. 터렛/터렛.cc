#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    int flag;
    while (n--) {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double plus=(r1+r2)*(r1+r2), minus=(r1-r2)*(r1-r2), distance=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if (distance==0) { 
            if (r1==r2) flag=-1;
            else flag=0;
        }
        else if (distance==plus) flag=1;
        else if (distance==minus) flag=1;
        else if (distance<minus) flag=0;
        else if (distance>plus) flag=0;
        else flag=2;
        cout << flag << "\n";
        }   
}