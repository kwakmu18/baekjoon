#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int X,Y;
    cin >> Y >> X;

    vector<vector<int>> paper(Y);

    for(int y=0;y<Y;y++) {
        paper[y].resize(X);
        for(int x=0;x<X;x++) cin >> paper[y][x];
    }

    int maxSum=0, sum;
    //유형 1-1
    for(int y=0;y<Y;y++) {
        for(int x=0;x<X-3;x++) {
            sum=paper[y][x]+paper[y][x+1]+paper[y][x+2]+paper[y][x+3];
            if (sum>maxSum) maxSum=sum;
        }
    }
    //유형 1-2
    for(int x=0;x<X;x++) {
        for(int y=0;y<Y-3;y++) {
            sum=paper[y][x]+paper[y+1][x]+paper[y+2][x]+paper[y+3][x];
            if (sum>maxSum) maxSum=sum;
        }
    }

    //유형 2
    for(int y=0;y<Y-1;y++) {
        for(int x=0;x<X-1;x++) {
            sum=paper[y][x]+paper[y+1][x]+paper[y][x+1]+paper[y+1][x+1];
            if (sum>maxSum) maxSum=sum;
        }
    }

    //유형 3-1
    for(int y=0;y<Y-2;y++) {
        for(int x=0;x<X;x++) {
            sum=paper[y][x]+paper[y+1][x]+paper[y+2][x];
            if (x==0) sum+=max(paper[y+2][x+1],paper[y][x+1]);
            else if (x==X-1) sum+=max(paper[y+2][x-1],paper[y][x-1]);
            else sum+=max(max(paper[y+2][x+1], paper[y+2][x-1]),max(paper[y][x+1], paper[y][x-1]));
            if (sum>maxSum) maxSum=sum;
        }
    }
    
    //유형 3-2
    for(int x=0;x<X-2;x++) {
        for(int y=0;y<Y;y++) {
            sum = paper[y][x]+paper[y][x+1]+paper[y][x+2];
            if (y==0) sum+=max(paper[y+1][x], paper[y+1][x+2]);
            else if (y==Y-1) sum+=max(paper[y-1][x], paper[y-1][x+2]);
            else sum+=max(max(paper[y+1][x], paper[y-1][x]),max(paper[y+1][x+2],paper[y-1][x+2]));
            if (sum>maxSum) maxSum=sum;
        }
    }

    //유형 4-1
    for(int x=0;x<X-1;x++) {
        for(int y=1;y<Y-1;y++) {
            sum=paper[y][x]+paper[y][x+1];
            sum+=max(paper[y-1][x]+paper[y+1][x+1], paper[y-1][x+1]+paper[y+1][x]);
            if (sum>maxSum) maxSum=sum;
        }
    }

    //유형 4-2
    for(int y=0;y<Y-1;y++) {
        for(int x=1;x<X-1;x++) {
            sum=paper[y][x]+paper[y+1][x];
            sum+=max(paper[y][x-1]+paper[y+1][x+1], paper[y][x+1]+paper[y+1][x-1]);
            if (sum>maxSum) maxSum=sum;
        }
    }

    //유형 5-1
    for(int x=0;x<X-2;x++) {
        for(int y=0;y<Y;y++) {
            sum=paper[y][x]+paper[y][x+1]+paper[y][x+2];
            if (y==0) sum+=paper[y+1][x+1];
            else if (y==Y-1) sum+=paper[y-1][x+1];
            else sum+=max(paper[y+1][x+1], paper[y-1][x+1]);
            if (sum>maxSum) maxSum=sum;
        }
    }

    //유형 5-2
    for(int y=0;y<Y-2;y++) {
        for(int x=0;x<X;x++) {
            sum=paper[y][x]+paper[y+1][x]+paper[y+2][x];
            if (x==0) sum+=paper[y+1][x+1];
            else if (x==X-1) sum+=paper[y+1][x-1];
            else sum+=max(paper[y+1][x+1], paper[y+1][x-1]);
            if (sum>maxSum) maxSum=sum;
        }
    }
    cout << maxSum;
}