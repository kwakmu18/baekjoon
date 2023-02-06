#include <bits/stdc++.h>

using namespace std;

int *zeroCnt;

string multiply(string a, string b) {
    vector<int> aDigits, bDigits;
    int aLen = a.length(), bLen = b.length();

    for(int i=0;i<aLen;i++) aDigits.push_back(a[i]-'0');
    for(int i=0;i<bLen;i++) bDigits.push_back(b[i]-'0');

    vector<int> cDigits(aLen+bLen);
    for(int i=0;i<cDigits.size();i++) cDigits[i]=0;
    
    int cLen = aLen+bLen;

    for(int i=0;i<bLen;i++) {
        for(int j=0;j<aLen;j++) {
            cDigits[i+j+1]+=bDigits[i]*aDigits[j];
        }
    }

    for(int i=cLen-1;i>0;i--) {
        if (cDigits[i]>=10) {
            cDigits[i-1]+=cDigits[i]/10;
            cDigits[i]%=10;
        }
    }

    int cIndex = 0, cLastIndex=cLen-1;
    while (cDigits[cIndex]==0) cIndex++;
    string ret = "";
    for(int i=cIndex;i<cLen;i++) ret+=(char)(cDigits[i]+'0');


    return ret;
    
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string n,m;
    cin >> n >> m;

    int nLen = n.length(), point = 0, mInt = stoi(m);
    while (n[point]!='.') point++;

    string integer = n.substr(0,point), decimal = n.substr(point+1);
    n = integer+decimal;

    string ans=n;
    for(int i=0;i<mInt-1;i++) {
        ans=multiply(n,ans);
    }

    int ansLen = ans.length(), pointPosition = ansLen-decimal.length()*mInt;
    if (integer=="0") {
        cout << "0.";
        for(int i=0;i<decimal.length()*mInt-ansLen;i++) cout << 0;
    }
    for(int i=0;i<ansLen;i++) {
        if (i==pointPosition) cout << ".";
        cout << ans[i];
    }
}