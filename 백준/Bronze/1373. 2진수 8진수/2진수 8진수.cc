#include <iostream>
#include <string>

using namespace std;

int caculate(char a, char b, char c) {
	return (a-'0')*4+(b-'0')*2+(c-'0');
}
int main(void) {
	string binary, oct="";
	cin >> binary;
	int len=binary.length();
	if (len%3!=0) {
		if ((len+1)%3==0) {
			binary="0"+binary;
			len++;
		}
		else {
			binary="00"+binary; 
			len+=2;
		}
	}
	for(int i=0;i<len;i+=3) {
		oct+=(caculate(binary[i], binary[i+1], binary[i+2])+'0');
	}
	cout << oct;
}