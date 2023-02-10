#include <iostream>
#include <vector>

using namespace std;

int n, node1, node2;
vector<vector<int>> vertex;
vector<bool> parent1;
void dfs1(int now) {
	parent1[now]=true;
	if (vertex[now].size()!=0) dfs1(vertex[now][0]);
}
void dfs2(int now) {
	if (parent1[now]) {
		cout << now << "\n";
		return;
	}
	dfs2(vertex[now][0]);
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, a, b;
	cin >> t;
	while (t--) {
		vertex.clear(); parent1.clear();
		cin >> n;
		vertex.resize(n+1);
		for(int i=0;i<n-1;i++) {
			cin >> a >> b;
			vertex[b].push_back(a);
		}
		cin >> node1 >> node2;
		parent1.resize(n+1);
		for(int i=1;i<=n;i++) parent1[i]=false;
		dfs1(node1);
		dfs2(node2);
	}
}