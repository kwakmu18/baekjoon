#include <bits/stdc++.h>

using namespace std;

int main(void) {
	set<int> paper;
	int n,x,y;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> x >> y;
		for(int j=x;j<x+10;j++) {
			for(int k=y;k<y+10;k++) paper.insert(j+100*k);
		}
	}
	cout << paper.size();
}