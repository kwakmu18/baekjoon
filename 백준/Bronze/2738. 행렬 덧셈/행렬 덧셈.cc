#include <iostream>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	int *arr=new int[n*m];
	for(int i=0;i<n*m;i++) cin >> arr[i];
	int add;
	for(int i=0;i<n*m;i++) {
		cin >> add;
		arr[i]+=add;
	}
	for(int i=1;i<=n*m;i++) {
		cout << arr[i-1];
		if (i%m==0) cout << "\n";
		else cout << " ";
	}
}