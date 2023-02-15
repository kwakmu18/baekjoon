#include <bits/stdc++.h>

using namespace std;

int visited[10];
int N, nextNum;
bool flag=false;

void dfs(int num) {
    if (flag) return;
    if (num>N) {
        if (num<nextNum) nextNum = num;
        return;
    }
    for(int i=1;i<=9;i++) {
        if (visited[i]) continue;
        int newNum = num*10+i;
        visited[i]=true;
        dfs(newNum);
        visited[i]=false;
    }
}

int main(void) {
    while (cin >> N) {
        if (N>987654321) {
            cout << "0\n";
            continue;
        }
        nextNum = 987654321;
        for(int i=0;i<10;i++) visited[i]=false;
        flag=false;
        dfs(0);
        cout << nextNum << "\n";
    }
}