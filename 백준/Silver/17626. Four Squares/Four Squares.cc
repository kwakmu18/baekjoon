#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> minCnt(50001,50001);
    int n;
    scanf("%d", &n);
    for(int i=0;i<=(int)sqrt(n);i++) minCnt[i*i]=1;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=(int)sqrt(n) && i+j*j<=n;j++) {
            int newCnt = minCnt[i]+1, newIndex = i+j*j;
            //cout << newCnt << " " << newIndex << "\n";
            if (minCnt[newIndex]>newCnt) minCnt[newIndex]=newCnt;
        }
    }
    printf("%d", minCnt[n]);
}