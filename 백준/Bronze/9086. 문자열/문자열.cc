#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	int n, len;
	cin >> n;
	while (n--) {
		cin >> s;
		len=s.length();
		cout << s[0] << s[len-1] << "\n";
	}
}