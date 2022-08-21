#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int pos[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(void) {
	int oneh, onew, nowh, noww, candw, candh;
	vector<vector<int>> board(5), length_map(5);

	for(int i=0;i<5;i++) {
		board[i].resize(5); length_map[i].resize(5);
		for(int j=0;j<5;j++) {
			cin >> board[i][j];
			if (board[i][j]==1) {
				oneh=i; onew=j;
			}
			length_map[i][j]=-1;
		}
	}

	cin >> nowh >> noww;
	length_map[nowh][noww]=0;

	queue<pair<int,int>> q; q.push({nowh, noww});
	while (!q.empty()) {
		nowh=q.front().first, noww=q.front().second; q.pop();
		for(int i=0;i<4;i++) {
			candh=nowh+pos[i][0]; candw=noww+pos[i][1];
			if (candh<0 || candw<0 || candh>4 || candw>4 || board[candh][candw]==-1) continue;
			else if (length_map[candh][candw]==-1) {
				q.push({candh, candw});
				length_map[candh][candw]=length_map[nowh][noww]+1;
			}
			else if (length_map[candh][candw]<length_map[nowh][noww]+1) continue;
			else {
				q.push({candh, candw});
				length_map[candh][candw]=length_map[nowh][noww]+1;
			}
		}
	}
	cout << length_map[oneh][onew];
}