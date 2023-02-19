#include <iostream>
using namespace std;
int main(void) {
	int n,t;
	cin >> t;
	while(t--) {
		cin >> n;
		int *zero=new int[n+1];
		int *one=new int[n+1];
		zero[0]=1;zero[1]=0;one[0]=0;one[1]=1;
			for(int i=2;i<=n;i++) {
				zero[i]=zero[i-2]+zero[i-1];
				one[i]=one[i-2]+one[i-1];
			}
			cout << zero[n] << " " << one[n] << endl;
		delete []zero;
		delete []one;
	}
	return 0;
}