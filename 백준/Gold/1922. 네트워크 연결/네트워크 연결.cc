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
    int V,E,a,b,c,totalWeight=0,edgeCount=0;
    cin >> V;
    cin >> E;
    int *parent = new int[V+1];
    for(int i=1;i<=V;i++) parent[i]=i;
    vector<pair<int, pair<int,int>>> edges(E);
    for(int i=0;i<E;i++) {
        cin >> a >> b >> c;
        if (a>b) edges[i]={c,{b,a}};
        else edges[i]={c,{a,b}};
    }
    sort(edges.begin(), edges.end());
    for(int i=0;i<E;i++) {
        if (edgeCount==V-1) break;
        c=edges[i].first; a=edges[i].second.first; b=edges[i].second.second;
        if ((a==b) || (find(parent,a)==find(parent,b))) continue;
        union_find(parent, a, b);
        totalWeight+=c; edgeCount++;
    }
    cout << totalWeight;
}