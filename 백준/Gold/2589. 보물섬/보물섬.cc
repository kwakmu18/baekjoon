#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int mov[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int height, width, max_hour=0, movh, movw, qh, qw;
	string line;
	cin >> height >> width;
	vector<vector<char>> treasure(height);
	vector<vector<int>> hour(height);
	for(int i=0;i<height;i++) {
		treasure[i].resize(width); hour[i].resize(width);
		cin >> line;
		for(int j=0;j<width;j++) {
			treasure[i][j]=line[j];
			hour[i][j]=-1;
		}
	}
	queue<pair<int,int>> q;
	for(int h=0;h<height;h++) {
		for(int w=0;w<width;w++) {
			if (treasure[h][w]=='W') continue;
			hour[h][w]=0;
			q.push({h,w});
			while (!q.empty()) {
				qh=q.front().first; qw=q.front().second; q.pop();
				
				for(int k=0;k<4;k++) {
					movh=qh+mov[k][0]; movw=qw+mov[k][1];
					if (movh<0 || movw<0 || movh>=height || movw>=width || treasure[movh][movw]=='W') continue;
					else if (hour[movh][movw]==-1) {
						hour[movh][movw]=hour[qh][qw]+1;
						q.push({movh, movw});
					}
					else if (hour[movh][movw]<hour[qh][qw]+1) continue;
					else {
						hour[movh][movw]=hour[qh][qw]+1;
					}
					if (max_hour<hour[movh][movw]) max_hour=hour[movh][movw];
					
				}
			}
			for(int k=0;k<height;k++) {
				for(int l=0;l<width;l++) hour[k][l]=-1;
			}
		}
	}
	cout << max_hour;
}