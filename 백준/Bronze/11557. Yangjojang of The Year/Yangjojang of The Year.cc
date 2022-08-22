#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	map<int, string> school;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		while (n--) {
			string name;
			int mount;
			cin >> name >> mount;
			school[mount]=name;
		}
		map<int, string>::iterator iter;
		iter=--school.end();
		cout << iter->second << "\n";
	} 
}