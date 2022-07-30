#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
	int a, b, size;
	cin >> a >> b;
	vector<vector<int>> number;
	number.resize(b+1); number[0].push_back(1);
	for(int i=2;i<=b;i++) {
		size=number[i].size();
		if (size==0) {
			for(int j=2*i;j<=b;j+=i) {
				int now=j;
				while (now%i==0) {
					number[j].push_back(i);
					now/=i;
				}
			}
		}
	}
	int ans=0;
	for(int i=a;i<=b;i++) {
		size=number[i].size();
		if (number[size].size()==0) ans++;
	}
	cout << ans;
}