#include <iostream>


using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
	int n; cin >> n;
	if (n<=4) {
		if (n==1) cout << 1;
		else if (n==2) cout << "1 2";
		else if (n==3) cout << "1 2 3";
		else cout << "2 4 1 3";
		return 0;
	}
	if (n%2==1) {
	cout << 1 << " " << n/2+1 << " " << n;
	for(int i=n/2;i>=2;i--) {
		cout << " " << i << " " << i+n/2;
	}
	}
	else {
		for(int i=n/2;i>=1;i--) cout << i << " " << i+n/2 << " ";
	}
}