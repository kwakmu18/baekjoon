#include <iostream>

using namespace std;

int main(void) {
	int x, n, a, b, total=0;
	cin >> x;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		total+=a*b;
	}
	cout << (total==x ? "Yes":"No");
}