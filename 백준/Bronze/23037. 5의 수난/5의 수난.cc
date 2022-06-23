#include <iostream>
#include <string>
using namespace std;
int five(char c) {
	int ret=c-'0';
	return ret*ret*ret*ret*ret;
}
int main(void) {
	string s;
	cin >> s;
	int len=s.length(), sum=0;
	for(int i=0;i<len;i++) {
		sum+=five(s[i]);
	}
	cout << sum;
}