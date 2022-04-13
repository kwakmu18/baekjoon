#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s;
    int row, col, slen;
    cin >> col;
    cin >> s;
    slen=s.length();
    row=slen/col;
    char **table=new char*[row];
    for(int i=0;i<row;i++) table[i]=new char[col];
    int index=0;

    for(int i=0;i<row;i++) {
        if (i%2==0) {
            for(int j=0;j<col;j++) {
                table[i][j]=s[index];
                index++;
            }
        }
        else {
            for(int j=col-1;j>=0;j--) {
                table[i][j]=s[index];
                index++;
            }
        }
    }
    for(int i=0;i<col;i++) {
        for(int j=0;j<row;j++) cout << table[j][i];
    }
}