#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(void) {
    cin.tie(0);
	map<string,bool> word;
	int n, m, cnt=0;
	string s;
	cin >> n >> m;
	while (n--) {
		cin >> s;
		word[s]=true;
	}
	while (m--) {
		cin >> s;
		if (word[s]) cnt++;
	}
	cout << cnt;
}