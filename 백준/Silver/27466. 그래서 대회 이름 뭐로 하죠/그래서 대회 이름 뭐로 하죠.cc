#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    string S, T="";
    int TLen = 0;
    
    cin >> N >> M;
    cin >> S;

    int index = N-1;
    
    while (index>=0 && (S[index]=='A' || S[index]=='E' && S[index]=='I' && S[index]=='O' && S[index]=='U')) index--;
    T=S[index--]+T; TLen++;
    while (index>=0 && S[index]!='A') index--;
    T=S[index--]+T; TLen++;
    while (index>=0 && S[index]!='A') index--;
    T=S[index--]+T; TLen++;
    while (index>=0 && TLen!=M) {
        T=S[index--]+T; TLen++;
    }
    if (TLen!=M) cout << "NO";
    else cout << "YES\n" << T;
}