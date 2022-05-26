#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
	long long n,m;
	cin >> n >> m;
	long long *tree=new long long[n];
	long long maxtree=0;
	for(int i=0;i<n;i++) {
		cin >> tree[i];
		if (maxtree < tree[i]) maxtree=tree[i];
	}
	long long left=0, right=maxtree, mid, ans;
	while (left<=right) {
		long long len=0;
		mid=(left+right)/2;
		for(int i=0;i<n;i++) len+=max((long long)0,tree[i]-mid);
		if (len>=m) {
			left=mid+1;
			ans=mid;
		}
		else right=mid-1;
	}
	cout << ans;
}