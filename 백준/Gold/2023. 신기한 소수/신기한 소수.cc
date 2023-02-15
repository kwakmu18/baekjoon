#include <bits/stdc++.h>
#define MAX 99999999
using namespace std;

int N, p;
int primes[6]={1,2,3,5,7,9};
bool flag=true;

void dfs(int num) {
    if ((num/p)>=10) return;
    else if ((num/p)==0) {
        for(int i=0;i<6;i++) {
            if (num==0 && i==0) continue;
            int newNum = num*10+primes[i];
            //cout << "newNum : " << newNum << "\n";
            flag=true;
            for(int j=2;j<=(int)sqrt(newNum);j++) {
                if (newNum%j==0) {
                    flag=false;
                    break;
                }
            }
            if (flag) dfs(newNum);
        }
    }
    else {
        for(int i=2;i<=(int)sqrt(num);i++) {
            if (num%i==0) return;
        }
        cout << num << "\n";
        return;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    p=(int)pow(10,N-1);

    dfs(0);
}