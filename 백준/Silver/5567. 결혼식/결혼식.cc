#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sang;
vector<bool> visited;
int cnt=0;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, a, b;
	cin >> n;
	cin >> m;
	sang.resize(n+1);
	visited.resize(n+1);
	for(int i=1;i<=6;i++) {
		visited[i]=false;
	}
	while (m--) {
		cin >> a >> b;
		sang[a].push_back(b);
		sang[b].push_back(a);
	}
	int size=sang[1].size();
	visited[1]=true;
	for(int i=0;i<size;i++) {
		int now=sang[1][i];
		if (!visited[now]) {
		cnt++; visited[now]=true;
		}
		int nowsize=sang[now].size();
		for(int j=0;j<nowsize;j++) {
			int now2=sang[now][j];
			if (!visited[now2]) {
			cnt++; visited[now2]=true;
			}
		}
	}
	cout << cnt;
}