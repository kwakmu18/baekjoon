#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	stack<int> st;
	int n;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		if (s=="push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (s=="top") {
			if (st.size()==0) cout << "-1\n";
			else cout << st.top() << "\n";
		}
		else if (s=="empty") {
			if (st.empty()) cout <<  "1\n";
			else cout << "0\n";
		}
		else if (s=="pop") {
			if (st.size()==0) cout << "-1\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (s=="size") {
			cout << st.size() << "\n";
		}
	}
}