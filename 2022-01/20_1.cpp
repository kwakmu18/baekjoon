//3613 Silver 4
#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string s;
    cin >> s;
    int len=s.length();
    if ((s[0]>=65 && s[0]<=90) || s[len-1]=='_' || s[0]=='_') {
        cout << "Error!";
        return 0;
    }
    bool isjava=true;
    bool underbar=false;
    for(int i=0;i<len-1;i++) {
        if (s[i]=='_') {
            if (underbar) {
                cout << "Error!";
                return 0;
            }
            if (s[i+1]>=65 && s[i+1]<=90) {
                cout <<"Error!";
                return 0;
            }
            isjava=false;
            underbar=true;
        }
        else underbar=false;
    }
    if (isjava) {
        for(int i=0;i<len;i++) {
            if (s[i]>=65 && s[i]<=90) {
                char c=s[i]+32;
                cout << "_" << c;
            }
            else cout << s[i];
        }
    }
    else {
        for(int i=0;i<len;i++) {
            if (s[i]>=65 && s[i]<=90) {
                cout << "Error!";
                return 0;
            }
        }
        for(int i=0;i<len;i++) {
            if (s[i]=='_') {
                s[i+1]-=32;
                continue;
            }
            cout << s[i];
        }
    }
}