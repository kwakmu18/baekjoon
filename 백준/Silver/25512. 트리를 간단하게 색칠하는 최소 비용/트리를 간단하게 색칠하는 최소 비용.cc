#include <bits/stdc++.h>

using namespace std;

int n, v1, v2, tmp;
vector<vector<int>> vertex;
vector<int> depth;
vector<pair<int,int>> cost;

void dfs(int now, int d) {
	depth[now]=d;
	int size=vertex[now].size();
	for(int i=0;i<size;i++) {
		dfs(vertex[now][i], d+1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vertex.resize(n+1); cost.resize(n+1); depth.resize(n+1);

	for(int i=0;i<n-1;i++) {
		cin >> v1 >> v2;
		vertex[v1].push_back(v2);
	}
	for(int i=0;i<n;i++) {
		cin >> cost[i].first >> cost[i].second;
	}
	
	dfs(0, 0);

	long long cost1=0, cost2=0;
	for(int i=0;i<n;i++) {
		if (depth[i]%2==0) {
			cost1+=cost[i].first;
			cost2+=cost[i].second;
		}
		else {
			cost1+=cost[i].second;
			cost2+=cost[i].first;
		}
	}
	cout << (cost1>cost2 ? cost2:cost1);
}