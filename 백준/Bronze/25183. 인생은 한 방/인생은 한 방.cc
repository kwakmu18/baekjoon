#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int n;
	cin >> n;
	cin >> s;
	int len=s.length();
	for(int i=0;i<=len-5;i++) {
		bool flag=true;
		for(int j=i;j<i+4;j++) {
			if (abs(s[j]-s[j+1])!=1) {
				flag=false; break;
			}
		}
		if (flag) {
			cout << "YES"; return 0;
		}
	}
	cout << "NO";
}