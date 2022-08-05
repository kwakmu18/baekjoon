#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n, getnum, i, j;
	cin >> m >> n;
	vector<int> sums;
	sums.resize(m+1);
	sums[0]=0;
	cin >> sums[1];
	for(int i=2;i<=m;i++) {
		cin >> getnum;
		sums[i]=sums[i-1]+getnum;
	}
	while (n--) {
		cin >> i >> j;
		cout << sums[j]-sums[i-1] << "\n";
	}
}