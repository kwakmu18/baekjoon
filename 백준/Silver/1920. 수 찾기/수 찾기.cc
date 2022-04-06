#include <iostream>
#include <map>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	map<int, bool> num;
	int n, m ,in;
	cin >> n;
	while (n--) {
		cin >> in;
		num[in] = true;
	}
	cin >> m;
	while (m--) {
		cin >> in;
		if (num[in]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}