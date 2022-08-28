#include <bits/stdc++.h>

using namespace std;

int n, k, v1, v2, tmp;
vector<vector<int>> vertex;
vector<int> value;
vector<int> depth;

void dfs(int now, int d) {
	depth[now]=d;
	int size=vertex[now].size();
	for(int i=0;i<size;i++) {
		dfs(vertex[now][i], d+1);
	}
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	vertex.resize(n+1); value.resize(n+1); depth.resize(n+1);

	for(int i=0;i<n-1;i++) {
		cin >> v1 >> v2;
		vertex[v1].push_back(v2);
	}
	for(int i=0;i<n;i++) {
		cin >> tmp;
		value[tmp]=i;
	}
	
	dfs(0, 0);

	cout << depth[value[k]];
}