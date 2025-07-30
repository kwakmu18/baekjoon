#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<string, string> map1;
	int n,m;
	cin >> n >> m;
	string url, password;
	while (n--) {
		cin >> url >> password;
		map1[url]=password;
	}
	while (m--) {
		cin >> url;
		cout << map1[url] << "\n";
	}
	return 0;
}