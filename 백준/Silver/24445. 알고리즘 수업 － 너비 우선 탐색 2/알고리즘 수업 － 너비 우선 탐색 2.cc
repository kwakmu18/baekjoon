#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
vector<vector<int>> vertex;
vector<int> visited;
int order=1;

void bfs(int first) {
	queue<int> q;
	q.push(first);
	visited[first]=order++;
	
	while (!q.empty()) {
		int now=q.front(); q.pop();
		int size=vertex[now].size();
		for(int i=size-1;i>=0;i--) {
			if (visited[vertex[now][i]]!=0) continue;
			visited[vertex[now][i]]=order; order++;
			q.push(vertex[now][i]);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b;
	cin >> n >> m >> r;
	vertex.resize(n+1); visited.resize(n+1);
	for(int i=1;i<=n;i++) visited[i]=0;
	while (m--) {
		cin >> a >> b;
		vertex[a].push_back(b); vertex[b].push_back(a);
	}
	for(int i=1;i<=n;i++) sort(vertex[i].begin(), vertex[i].end());
	bfs(r);
	for(int i=1;i<=n;i++) cout << visited[i] << "\n";
}