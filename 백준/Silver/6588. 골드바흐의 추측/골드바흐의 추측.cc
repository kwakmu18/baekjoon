#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	bool *prime=new bool[1000001]{0};
	for(int i=2;i<=1000000;i++) {
		if (!prime[i]) {
			for(int j=i*2;j<=1000000;j+=i) prime[j]=true;
		}
	}
	cin >> n;
	while (n!=0) {
		k=n-2;
		while (k>=(n/2)) {
			if (!prime[k] && !prime[n-k]) {
				cout << n << " = " << n-k << " + " << k << "\n";
				break;
			}
			k--;
		}
		cin >> n;
	}
}