#include <bits/stdc++.h>

using namespace std;

void main_function(int, int);
int calculate_bill(int);
int calculate_Wh(int);

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a==0 && b==0) break;
		main_function(a,b);
	}
}

void main_function(int plus_Wh_bill, int diff_bill) {
	int ab_Wh=calculate_Wh(plus_Wh_bill), binary_Wh, left=0, right=ab_Wh, mid;
	while (left<=right) {
		mid=(left+right)/2;
		binary_Wh=abs(calculate_bill(mid)-calculate_bill(ab_Wh-mid));
		if (binary_Wh==diff_bill) break;
		else if (binary_Wh>diff_bill) right=mid-1;
		else left=mid+1;
	}
	cout << calculate_bill(min(mid, ab_Wh-mid)) << "\n";
}

int calculate_bill(int wh) {
	if (wh<=100) return wh*2;
	else if (wh<=10000) return 200+(wh-100)*3;
	else if (wh<=1000000) return 29900+(wh-10000)*5;
	else return 4979900+(wh-1000000)*7;
}

int calculate_Wh(int bill) {
	if (bill<=200) return bill/2;
	else if (bill<=29900) return 100+(bill-200)/3;
	else if (bill<=4979900) return 10000+(bill-29900)/5;
	else return 1000000+(bill-4979900)/7;
}