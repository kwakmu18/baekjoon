#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vertex;
vector<int> parent;
int n, p, root, del, cnt;

void dfs(int now) {
	int size=vertex[now].size();
	for(int i=0;i<size;i++) {
		dfs(vertex[now][i]);
	}
	vertex[now].push_back(999);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vertex.resize(n); parent.resize(n);
	for(int i=0;i<n;i++) {
		cin >> p;
		if (p==-1) root=i;
		else vertex[p].push_back(i);
		parent[i]=p;
	}
	cin >> del;
	if (del==root) {
		cout << 0;
		return 0;
	}
	auto iter=find(vertex[parent[del]].begin(), vertex[parent[del]].end(), del);
	vertex[parent[del]].erase(iter);
	dfs(del);
	for(int i=0;i<n;i++) {
		if (vertex[i].size()==0) cnt++;
	}
	cout << cnt;
}