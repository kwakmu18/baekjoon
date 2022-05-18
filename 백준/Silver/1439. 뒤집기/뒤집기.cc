#include <iostream>
#include <string>
#define CMP(x,y) (x<y ? x:y)
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int len=s.length();
    if (len==1) {
        cout << 0;
        return 0;
    }
    int zerocnt=0, onecnt=0, index=0;
    while (index<len) {
        if (s[index]=='0') {
            while (s[index]=='0') {
                index++;
                if (index==len) break;
            }
            zerocnt++;
        }
        else {
            while (s[index]=='1') {
                index++;
                if (index==len) break;
            };
            onecnt++;
        }
    }
    cout << CMP(zerocnt, onecnt);
}