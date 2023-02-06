#include <bits/stdc++.h>

using namespace std;

string inst[10000];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int A,B;
        cin >> A >> B;

        for(int i=0;i<10000;i++) inst[i]="";

        queue<int> q;
        q.push(A);

        while (!q.empty()) {
            int nowNumber = q.front();
            q.pop();

            int D=(nowNumber*2)%10000, 
            S = (nowNumber + 9999) % 10000, 
            L = (nowNumber * 10) % 10000 + (nowNumber/1000), 
            R = nowNumber / 10 + (nowNumber % 10) * 1000 ;


            string nowInst = inst[nowNumber];
            int nowLength = nowInst.length();
            if (nowNumber==B) {
                cout << inst[B] << "\n";
                break;
            }
            else if (nowNumber==0) {
                if (inst[S]=="" || inst[S].length()>nowLength+1) {
                    inst[S]=nowInst+"S";
                    q.push(S);
                }
            }
            else {
                if (inst[D]=="" || inst[D].length()>nowLength+1) {
                    inst[D]=nowInst+"D";
                    q.push(D);
                }
                if (inst[S]=="" || inst[S].length()>nowLength+1) {
                    inst[S]=nowInst+"S";
                    q.push(S);
                }
                if (inst[L]=="" || inst[L].length()>nowLength+1) {
                    inst[L]=nowInst+"L";
                    q.push(L);
                }
                if (inst[R]=="" || inst[R].length()>nowLength+1) {
                    inst[R]=nowInst+"R";
                    q.push(R);
                }
            }
        }
    }
}