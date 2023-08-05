#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int N;
char image[7000][7000];

void func(int y, int x, int size) {
    if (size==3) {
        image[y][x+2]='*';
        image[y+1][x+1]=image[y+1][x+3]='*';
        for(int i=x;i<x+5;i++) image[y+2][i]='*';
    }
    else {
        size/=2;
        func(y,x+size,size);
        func(y+size,x, size);
        func(y+size,x+6*(size/3), size);
    }
}

int main(void) {
    fastio;
    cin >> N;
    func(0,0,N);
    for(int i=0;i<N;i++) {
        for(int j=0;j<6*(N/3)-1;j++) cout << (image[i][j]==0 ? " ":"*");
        cout << "\n";
    }
}