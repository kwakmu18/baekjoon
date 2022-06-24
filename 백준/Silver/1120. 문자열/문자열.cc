#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;
	int alen=a.length(), blen=b.length(), diff1=0, diff2=99999;
	if (alen==blen) {
		for(int i=0;i<alen;i++) {
			if (a[i]!=b[i]) diff1++;
		}
		cout << diff1;
	}
	else if (alen<blen) {
		for(int i=0;i<=blen-alen;i++) {
			diff1=0;
			for(int j=0;j<alen;j++) {
				if (a[j]!=b[i+j]) diff1++;
			}
			diff2=min(diff2, diff1);
		}
		cout << diff2;
	}
	else {
		for(int i=0;i<=alen-blen;i++) {
			diff1=0;
			for(int j=0;j<blen;j++) {
				if (a[i+j]!=b[j]) diff1++;
			}
			diff2=min(diff2, diff1);
		}
		cout << diff2;
	}
}