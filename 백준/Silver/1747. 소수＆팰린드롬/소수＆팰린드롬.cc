#include <bits/stdc++.h>
#define MAX 1003002
using namespace std;

bool ispel(int num) {
    string numtos = to_string(num);
    int size=numtos.length();
    for(int i=0;i<size/2;i++) {
        if (numtos[i]!=numtos[size-i-1]) return false;
    }
    return true;
}

int main(void) {
    bool prime[MAX]{0};
    vector<int> prime_and_pelin;
    for(int i=2;i<=MAX;i++) {
        if (!prime[i]) {
            if (ispel(i)) prime_and_pelin.push_back(i);
            for(int j=i*2;j<=MAX;j+=i) prime[j]=true;
        }
    }
    int input, index=0;
    cin >> input;
    while (prime_and_pelin[index]<input) index++;
    cout << prime_and_pelin[index];
}