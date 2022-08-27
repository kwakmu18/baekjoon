#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	bool *prime_order=new bool[100001]{0};
	bool *prime=new bool[100001]{0};
	for(int i=2;i<=100000;i++) {
		if (!prime[i]) {
			for(int j=i*2;j<=100000;j+=i) prime[j]=true;
		}
	}
	vector<pair<int,int>> accumulated(100001);
	accumulated[1]={0,0};
	int order=1;
	for(int i=2;i<=100000;i++) {
		accumulated[i]=accumulated[i-1];
		if (!prime[i]) {
			if (order%2==0) {
				accumulated[i].second+=i;
				prime_order[i]=true;
			}
			else {
				accumulated[i].first+=i;
				prime_order[i]=false;
			}
			order++;
		}
	}
	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		while (prime[a]) a++;
		if (!prime_order[a]) cout << (accumulated[b].first-accumulated[a-1].first)*3-(accumulated[b].second-accumulated[a-1].second) << "\n";
		else cout << (accumulated[b].second-accumulated[a-1].second)*3-(accumulated[b].first-accumulated[a-1].first) << "\n";
	}
}