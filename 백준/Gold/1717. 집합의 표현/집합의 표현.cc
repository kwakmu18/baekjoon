#include <bits/stdc++.h>

using namespace std;

int find(int parent[], int k) {
    if (parent[k]==k) return k;
    else return parent[k]=find(parent, parent[k]);
}

void union_find(int parent[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    parent[b]=a;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,type,a,b;
    cin >> n >> m;
    int *parent = new int[n+1];
    for(int i=0;i<=n;i++) parent[i]=i;

    while (m--) {
        cin >> type >> a >> b;
        if (type==0) {
            if (a>b) union_find(parent, b,a);
            else union_find(parent, a,b);
        }
        else {
            if (find(parent, a) == find(parent, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}