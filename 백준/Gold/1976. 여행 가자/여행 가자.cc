#include <bits/stdc++.h>

using namespace std;

int find(int p[], int k) {
    if (p[k]==k) return k;
    return p[k]=find(p, p[k]);
}

void union_find(int p[], int a, int b) {
    a=find(p,a); b=find(p,b);
    p[b]=a;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int v,t;
    bool isConnect;
    cin >> v; cin >> t;
    int *parent = new int[v+1];
    for(int i=1;i<=v;i++) parent[i]=i;
    
    for(int i=1;i<=v;i++) {
        for(int j=1;j<=v;j++) {
            cin >> isConnect;
            if (isConnect) {
                if (i>j) union_find(parent,j,i);
                else union_find(parent,i,j);
            }
        }
    }
    int a,b;
    cin >> a;
    for(int i=0;i<t-1;i++) {
        cin >> b;
        if (find(parent, a)!=find(parent,b)) {
            cout << "NO"; return 0;
        }
        a=b;
    }
    cout << "YES";
    return 0;
}