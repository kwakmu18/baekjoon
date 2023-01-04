#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N,M,A,B,T,X,Y,nowtime,nowtown;
	cin >> N;
	cin >> M;
	vector<vector<pair<int,int>>> road(N);
	vector<vector<int>> road_candidate(N);
	for(int i=0;i<N;i++) {
		road_candidate[i].resize(N);
		for(int j=0;j<N;j++) road_candidate[i][j]=100000;
	}
	for(int i=0;i<M;i++) {
		cin >> A >> B >> T;
		if (road_candidate[A-1][B-1]>T) road_candidate[A-1][B-1]=T;
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if (road_candidate[i][j]!=100000) road[i].push_back({road_candidate[i][j],j});
		}
	}
	cin >> X >> Y;
	vector<int> length(N);
	for(int i=0;i<N;i++) length[i]=200000000;
	length[X-1]=0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,X-1});
	while (!pq.empty()) {
		pair<int,int> now=pq.top();
		pq.pop();
		nowtime=now.first; nowtown=now.second;
		int size=road[nowtown].size();
		for(int i=0;i<size;i++) {
			if (length[road[nowtown][i].second]>nowtime+road[nowtown][i].first) {
				length[road[nowtown][i].second]=nowtime+road[nowtown][i].first;
				pq.push({nowtime+road[nowtown][i].first,road[nowtown][i].second});
			}
		}
	}
	cout << length[Y-1];
}