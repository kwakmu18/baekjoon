#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void) {
	int l;
	cin >> l;
	string s;
	cin >> s;
	long long ans=0,num;
	for(int i=0;i<l;i++) {
		num=s[i]-96;
		for(int j=0;j<i;j++) {
			num*=31;
			num%=1234567891;
		}
		ans+=num%1234567891;
	}
	cout << ans%1234567891;
	return 0;
}