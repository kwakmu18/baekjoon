#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int mov[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, w, nowh, noww, candh, candw;
	string s;

	cin >> h >> w;

	vector<vector<bool>> maze(h);
	vector<vector<int>> length(h);
	for(int i=0;i<h;i++) {
		maze[i].resize(w); length[i].resize(w);
		cin >> s;
		for(int j=0;j<w;j++) {
			maze[i][j]=s[j]-'0';
			length[i][j]=-1;
		}
	}
	length[0][0]=1;
	
	queue<pair<char, char>> q; q.push({0,0});
	while (!q.empty()) {
		nowh=q.front().first; noww=q.front().second; q.pop();
		for(int i=0;i<4;i++) {
			candh=nowh+mov[i][0]; candw=noww+mov[i][1];
			if (candh<0 || candh>=h || candw<0 || candw>=w || maze[candh][candw]==0) continue;
			else if (length[candh][candw]==-1) {
				length[candh][candw]=length[nowh][noww]+1;
				q.push({candh, candw});
			}
			else if (length[candh][candw]<length[nowh][noww]+1) continue;
			else {
				length[candh][candw]=length[nowh][noww]+1;
				//q.push({candh, candw});
			}
		}
	}
	cout << length[h-1][w-1];
	return 0;
}