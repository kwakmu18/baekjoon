#include <iostream>

using namespace std;
int k, n;
bool islong(long long lan[], int length) {
	int cnt=0;
	for(int i=0;i<k;i++) cnt+=lan[i]/length;
	return cnt>=n;
}
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k >> n;
	long long *lan=new long long[k];
	long long maxlan=0, ans=2;
	for(int i=0;i<k;i++) {
		cin >> lan[i];
		maxlan=max(maxlan, lan[i]);
	}
	long long left=1, right=maxlan, mid;
	while (left<=right) {
		mid=(left+right)/2;
		if (islong(lan, mid)) {
			left=mid+1;
			ans=mid;
		}
		else right=mid-1;
	}
	cout << ans;
}