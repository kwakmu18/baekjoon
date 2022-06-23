#include <iostream>
using namespace std;

int main(void) {
    cin.tie(0);
	int n, getnum, chk;
	cin >> n;
	int *pos=new int[101]{0};
	int *neg=new int[101]{0};
	int zero=0;
	for(int i=0;i<n;i++) {
		cin >> getnum;
		if (getnum>0) pos[getnum]++;
		else if (getnum==0) zero++;
		else neg[-1*getnum]++;
	}
	cin >> chk;
	if (chk>0) cout << pos[chk];
	else if (chk==0) cout << zero;
	else cout << neg[-1*chk];
}