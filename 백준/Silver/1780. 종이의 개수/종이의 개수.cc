#include <bits/stdc++.h>

using namespace std;

int m,z,p;
int **paper;

bool check(int row, int col, int size) {
    for(int i=row;i<row+size;i++) {
        for(int j=col;j<col+size;j++) {
            if (paper[i][j]!=paper[row][col]) return false;
        }
    }
    return true;
}

void part(int row, int col, int size) {
    if (check(row,col,size)) {
        if (paper[row][col]==-1) m++;
        else if (paper[row][col]==0) z++;
        else p++;
        return;
    }
    size/=3;
    int row_s=row+size, row_ss=row+2*size, col_s=col+size, col_ss=col+size*2;
    part(row,col,size);
    part(row_s,col,size);
    part(row_ss,col,size);
    part(row,col_s,size);
    part(row_s,col_s,size);
    part(row_ss,col_s,size);
    part(row,col_ss,size);
    part(row_s,col_ss,size);
    part(row_ss,col_ss,size);
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
    cout << m << "\n" << z << "\n" << p;
}