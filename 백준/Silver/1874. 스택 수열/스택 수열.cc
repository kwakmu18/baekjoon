#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t;
	cin >> n;
	stack<int> st;
	vector<char> pushpop;
	int nownum=1;
	bool flag=true;
	for(int i=0;i<n;i++) {
		cin >> t;
		if (nownum<=t) {
			for(nownum;nownum<=t;nownum++) {
				st.push(nownum);
				pushpop.push_back('+');
			}
		}
		if (st.top()==t) {
			st.pop();
			pushpop.push_back('-');
		}
		else {
			flag=false;
			break;
		}
	}
	if (!flag) cout << "NO";
	else {
		for(auto i=pushpop.begin();i!=pushpop.end();i++) cout << *i << "\n";
	}
}