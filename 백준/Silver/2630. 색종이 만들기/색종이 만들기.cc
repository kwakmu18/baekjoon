#include <bits/stdc++.h>

using namespace std;

int blue, white;
int **paper;

bool check(int row, int col, int size) {
    for(int i=row;i<row+size;i++) {
        for(int j=col;j<col+size;j++) {
            if (paper[row][col]!=paper[i][j]) return false;
        }
    }
    return true;
}

void part(int row, int col, int size) {
    if (check(row, col, size)) {
        if (paper[row][col]==0) white++;
        else blue++;
        return;
    }
    size/=2;
    part(row, col, size);
    part(row, col+size, size);
    part(row+size, col, size);
    part(row+size, col+size, size);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    paper = new int *[N];
    for(int i=0;i<N;i++) {
        paper[i] = new int[N];
        for(int j=0;j<N;j++) cin >> paper[i][j];
    }
    part(0,0,N);
    cout << white << "\n" << blue;
    return 0;
}