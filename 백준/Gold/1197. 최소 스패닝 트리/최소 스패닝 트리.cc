#include <bits/stdc++.h>

using namespace std;

int find(int p[], int k) {
    if (p[k]==k) return k;
    else return p[k]=find(p, p[k]);
}

void union_find(int p[], int a, int b) {
    a=find(p,a); b=find(p,b);
    p[b]=a;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int V, E, totalWeight=0, edgeCount=0, A,B,C;
    cin >> V >> E;
    int *parent = new int[V+1];
    for(int i=1;i<=V;i++) parent[i]=i;

    vector<pair<int, pair<int,int>>> edges(E);
    for(int i=0;i<E;i++) {
        cin >> A >> B >> C;
        if (A>B) edges[i]={C, {B,A}};
        else edges[i]={C, {A,B}};
    }
    sort(edges.begin(), edges.end());

    for(int i=0;i<E;i++) {
        if (edgeCount==V-1) break;
        C=edges[i].first; A=edges[i].second.first; B=edges[i].second.second;
        if (find(parent, A)==find(parent, B)) continue;
        union_find(parent, A, B);
        edgeCount++; totalWeight+=C;
    }
    cout << totalWeight;
}