#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int> pq;
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		if (num==0) {
			if(pq.size()==0) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(num);
	}
}