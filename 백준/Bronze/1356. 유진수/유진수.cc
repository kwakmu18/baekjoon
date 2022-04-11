#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	if (n==1) {
		cout << "NO";
		return 0;
	} 
	string s=to_string(n);
	bool istrue=false;
	for(int i=0;i<s.length();i++) {
		int front=1, back=1;
		for(int j=0;j<=i;j++) front*=(s[j]-'0');
		for(int j=i+1;j<s.length();j++) back*=(s[j]-'0');
		if (front==back) {
			istrue=true;
			break;
		}
	}
	if (istrue) cout << "YES";
	else cout << "NO";
}