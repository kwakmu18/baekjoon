#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b) {
	return a>b;
}
int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> score; score.resize(n);
	for(int i=0;i<n;i++) cin >> score[i];
	sort(score.begin(), score.end(), compare);
	cout << score[k-1];
}