#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, inventory, minh=256, maxh=0, temph, mint=127744510;
	cin >> n >> m >> inventory;
	int height[257]={0,};
	int time[257]={0,};
	for(int i=0;i<n*m;i++) {
		cin >> temph;
		height[temph]++;
		maxh=max(maxh, temph);
		minh=min(minh, temph);
	}
	for(int i=maxh;i>=minh;i--) {
		int t=0;
		int upper=0, lower=0;
		for(int j=minh;j<i;j++) lower+=(i-j)*height[j];
		for(int j=maxh;j>i;j--) upper+=(j-i)*height[j];
		if (lower==0) t=upper*2;
		else if (upper==0) {
			if (lower<=inventory) t=lower;
			else t=-1;
		}
		else {
			if (upper+inventory>=lower) t=upper*2+lower;
			else t=-1;
		}
		time[i]=t;
		}
	int minans;
	for(int i=maxh;i>=minh;i--) {
		if (mint>time[i] && time[i]!=-1) {
			mint=time[i];
			minans=i;
		}
	}
	cout << mint << " " << minans;
}