#include <bits/stdc++.h>

using namespace std;

string compressed="";
int **video;

bool check(int row, int col, int size) {
    for(int i=row;i<row+size;i++) {
        for(int j=col;j<col+size;j++) {
            if (video[row][col]!=video[i][j]) return false;
        }
    }
    return true;
}

void part(int row, int col, int size) {
    if (check(row, col, size)) {
        if (video[row][col]==0) compressed+="0";
        else compressed+="1";
        return;
    }

    size/=2;
    compressed+="(";
    part(row,col,size);
    part(row,col+size,size);
    part(row+size,col,size);
    part(row+size,col+size,size);
    compressed+=")";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    string input;
    cin >> N;
    video = new int *[N];
    for(int i=0;i<N;i++) {
        video[i]=new int[N];
        cin >> input;
        for(int j=0;j<N;j++) video[i][j]=(int)(input[j]-'0');
    }
    part(0,0,N);
    cout << compressed;
}