#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int citycnt, roadcnt, length, start, src, dst, qnow, mov, flag=0;
	cin >> citycnt >> roadcnt >> length >> start;
	vector<vector<int>> country(citycnt+1);
	vector<int> city2city(citycnt+1);
	for(int i=0;i<roadcnt;i++) {
		cin >> src >> dst;
		country[src].push_back(dst);
	}
	for(int i=1;i<=citycnt;i++) city2city[i]=-1;
	city2city[start]=0;
	queue<int> q; q.push(start);
	while (!q.empty()) {
		qnow=q.front(); q.pop();
		int size=country[qnow].size();
		for(int i=0;i<size;i++) {
			mov=country[qnow][i];
			if (city2city[mov]==-1) {
				city2city[mov]=city2city[qnow]+1;
				q.push(mov);
			}
			else if (city2city[mov]<city2city[qnow]+1) continue;
			else city2city[mov]=city2city[qnow]+1;
		}
	}
	for(int i=1;i<=citycnt;i++) {
		if (city2city[i]==length) cout << i << "\n";
		else flag++;
	}
	if (flag==citycnt) cout << -1;
}