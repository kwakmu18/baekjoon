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
    while (cDigits[cLastIndex]==0 && cLastIndex>0) cLastIndex--;
    zeroCnt[stoi(b)]=zeroCnt[stoi(b)-1]+(cLen-cLastIndex-1);
    string ret = "";
    for(int i=cIndex;i<=cLastIndex;i++) ret+=(char)(cDigits[i]+'0');


    return ret;
    
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    string facto[N+1];
    zeroCnt=new int[N+1];
    zeroCnt[0]=0;
    zeroCnt[1]=0;
    facto[0]="1";
    for(int i=1;i<=N;i++) {
        facto[i]=multiply(facto[i-1],to_string(i));
    }
    cout << zeroCnt[N];
}