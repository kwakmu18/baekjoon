#include <iostream>
#include <string>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, t;
	cin >> t;
	bool *set=new bool[20]{0};
	string s;
	while (t--) {
		cin >> s;
		if (s=="add") {
			cin >> n;
			set[n-1]=true;
		}
		else if (s=="remove") {
			cin >> n;
			set[n-1]=false;
		}
		else if (s=="check") {
			cin >> n;
			if (set[n-1]) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s=="toggle") {
			cin >> n;
			if (set[n-1]) set[n-1]=false;
			else set[n-1]=true;
		}
		else if (s=="all") {
			for(int i=0;i<20;i++) set[i]=true;
		}
		else if (s=="empty") {
			for(int i=0;i<20;i++) set[i]=false;
		}
	}
	return 0;
}