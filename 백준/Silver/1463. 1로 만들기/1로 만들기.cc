#include <bits/stdc++.h>

using namespace std;

short min(short a, short b) {
    if (a<b) return a;
    else return b;
}

int main(void) {
    vector<short> mincnt(1000002);
    mincnt[1]=0; mincnt[2]=1; mincnt[3]=1;
    int tmp=1;
    while (tmp<=999999) {
        if (tmp<=500000) {
            if (mincnt[tmp*2]==0) mincnt[tmp*2]=mincnt[tmp]+1;
            else mincnt[tmp*2]=min(mincnt[tmp*2], mincnt[tmp]+1);

            if (mincnt[tmp*2+1]==0) mincnt[tmp*2+1]=mincnt[tmp]+2;
            else mincnt[tmp*2+1]=min(mincnt[tmp*2+1], mincnt[tmp]+2);

            if (tmp<=333333) {
                if (mincnt[tmp*3]==0) mincnt[tmp*3]=mincnt[tmp]+1;
                else mincnt[tmp*3]=min(mincnt[tmp*3], mincnt[tmp]+1);

                if (mincnt[tmp*3+1]==0) mincnt[tmp*3+1]=mincnt[tmp]+2;
                else mincnt[tmp*3+1]=min(mincnt[tmp*3+1], mincnt[tmp]+2);
            }
        }
            if (mincnt[tmp+1]==0) mincnt[tmp+1]=mincnt[tmp]+1;
            else mincnt[tmp+1]=min(mincnt[tmp+1], mincnt[tmp]+1);
        tmp++;
    }
    int n;
    cin >> n;
    cout << mincnt[n];
}