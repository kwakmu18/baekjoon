#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int number[5], sum=0;
	for(int i=0;i<5;i++) {
		cin >> number[i];
		sum+=number[i];
	}
	sort(number, number+5);
	cout << sum/5 << "\n" << number[2];
}